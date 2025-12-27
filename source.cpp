#include "header.h"

//// Membuat dan menambahkan node
adr createNode(string title, string url) {
    adr P = new Node;
    P->info.title = title;
    P->info.url = url;
    P->firstChild = NULL;
    P->nextSibling = NULL;
    return P;
}

void addChild(adr root, adr parent, string title, string url) {
    if (parent != NULL) {
        if (searchByURL(root, url) != NULL) {
            cout << "Error: URL '" << url << "' sudah digunakan oleh halaman lain!" << endl;
            return;
        }

        adr newChild = createNode(title, url);
        if (parent->firstChild == NULL) {
            parent->firstChild = newChild;
        } else {
            adr temp = parent->firstChild;
            while (temp->nextSibling != NULL) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = newChild;
        }
        cout << "Sukses: Halaman berhasil ditambahkan." << endl;
    }
}
////


//// Menghapus seluruh sub-tree secara rekursif
// Kondisional Khusus untuk menghapus keseluruhan tree
void deleteTree(adr &P) {
    if (P != NULL) {
        deleteTree(P->firstChild);
        deleteTree(P->nextSibling);
        delete P;
        P = NULL;
    }
}

// Kondisional untuk menghapus parent dan semua childnya
void findAndDisconnect(adr parent, string targetTitle) {
    if (parent == NULL) return;

    adr curr = parent->firstChild;
    adr prev = NULL;

    while (curr != NULL) {
        if (curr->info.title == targetTitle) {
            if (prev == NULL) {
                parent->firstChild = curr->nextSibling;
            } else {
                prev->nextSibling = curr->nextSibling;
            }
            curr->nextSibling = NULL;
            deleteTree(curr);
            return;
        }
        findAndDisconnect(curr, targetTitle);
        prev = curr;
        curr = curr->nextSibling;
    }
}

// Main method penghapusan
void deletePage(adr &root, string targetTitle) {
    if (root == NULL) return;
    if (root->info.title == targetTitle) {
        deleteTree(root);
    } else {
        findAndDisconnect(root, targetTitle);
    }
}
////

//// Menampilkan sitemap
// Standar
void printSitemap(adr root, int indent) {
    if (root != NULL) {
        for (int i = 0; i < indent; i++) cout << "    ";
        cout << "|-- " << root->info.title << " (" << root->info.url << ")" << endl;
        printSitemap(root->firstChild, indent + 1);
        printSitemap(root->nextSibling, indent);
    }
}

// Pre-Order
void printPreOrder(adr root) {
    if (root != NULL) {
        cout << root->info.title << " | ";
        printPreOrder(root->firstChild);
        printPreOrder(root->nextSibling);
    }
}

// Post-Order
void printPostOrder(adr root) {
    if (root != NULL) {
        printPostOrder(root->firstChild);
        cout << root->info.title << " | ";
        printPostOrder(root->nextSibling);
    }
}

// In-Order
void printInOrder(adr root) {
    if (root != NULL) {
        if (root->firstChild != NULL) printInOrder(root->firstChild);
        cout << root->info.title << " | ";
        if (root->firstChild != NULL) printInOrder(root->firstChild->nextSibling);
        printInOrder(root->nextSibling);
    }
}
////

//// Pencarian Node
// Pencarian berdasarkan nama Page
adr searchPage(adr root, string targetTitle) {
    if (root == NULL) return NULL;
    if (root->info.title == targetTitle) return root;

    adr found = searchPage(root->firstChild, targetTitle);
    if (found == NULL) {
        found = searchPage(root->nextSibling, targetTitle);
    }
    return found;
}

// Pecarian berdasarkan URL
adr searchByURL(adr root, string targetURL) {
    if (root == NULL) return NULL;
    if (root->info.url == targetURL) return root;

    adr found = searchByURL(root->firstChild, targetURL);
    if (found == NULL) {
        found = searchByURL(root->nextSibling, targetURL);
    }
    return found;
}

// Menampilkan hasil pencarian
bool printPagePath(adr root, string targetTitle, string currentPath) {
    if (root == NULL) return false;

    string newPath = currentPath + "/" + root->info.url;
    if (root->info.title == targetTitle) {
        cout << "Path: " << newPath << endl;
        return true;
    }

    if (printPagePath(root->firstChild, targetTitle, newPath)) return true;
    if (printPagePath(root->nextSibling, targetTitle, currentPath)) return true;

    return false;
}
////

//// Menghitung banyak node
int countTotalPages(adr root) {
    if (root == NULL) return 0;
    return 1 + countTotalPages(root->firstChild) + countTotalPages(root->nextSibling);
}
////
