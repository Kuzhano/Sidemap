#include <limits>
#include "header.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    adr root = createNode("Home", "home");

    addChild(root, root, "Profil", "profile");
    addChild(root, root, "Produk", "products");
    addChild(root, root, "Berita", "news");

    adr nodeProfil = searchPage(root, "Profil");
    addChild(root, nodeProfil, "Sejarah", "history");
    addChild(root, nodeProfil, "Visi Misi", "vision");

    adr nodeProduk = searchPage(root, "Produk");
    addChild(root, nodeProduk, "Elektronik", "electronics");
    addChild(root, nodeProduk, "Fashion", "fashion");
    addChild(root, nodeProduk, "Otomotif", "automotive");

    int pilihan = -1;
    string input;
    string parentTitle, newTitle, newUrl;
    adr parentNode;

    clearScreen();

    do {
        cout << "\n=======================================" << endl;
        cout << "======= GENERAL TREE SITEMAP GEN ======" << endl;
        cout << "=======================================" << endl;
        cout << "1. Tampilkan Sitemap (Hierarchy)" << endl;
        cout << "2. Tambah Halaman Baru (Child)" << endl;
        cout << "3. Cari Halaman & Jalur URL" << endl;
        cout << "4. Info Statistik & Traversal" << endl;
        cout << "5. Hapus Halaman & Keturunannya" << endl;
        cout << "0. Keluar" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu [0-5]: ";
        getline(cin, input);

        try {
            pilihan = input.empty() ? -1 : stoi(input);
        } catch (...) {
            pilihan = -1;
        }

        cout << endl;

        switch (pilihan) {
        case 1:
            cout << "[ Struktur Website Saat Ini ]" << endl;
            if (root == NULL) {
                cout << "Sitemap kosong!" << endl;
            } else {
                printSitemap(root, 0);
            }
            break;

        case 2:
            cout << "--- Tambah Halaman Baru ---" << endl;

            if (root == NULL) {
                cout << "Tree kosong. Masukkan Judul untuk Root baru: ";
                getline(cin, newTitle);
                cout << "Masukkan URL Root: ";
                getline(cin, newUrl);
                root = createNode(newTitle, newUrl);
                cout << "Root '" << newTitle << "' berhasil dibuat." << endl;
            } else {
                cout << "Masukkan Judul Halaman Induk (Parent): ";
                getline(cin, parentTitle);

                parentNode = searchPage(root, parentTitle);

                if (parentNode == NULL) {
                    cout << "Error: Halaman induk tidak ditemukan!" << endl;
                } else {
                    cout << "Masukkan Judul Halaman Baru: ";
                    getline(cin, newTitle);
                    cout << "Masukkan URL: ";
                    getline(cin, newUrl);

                    addChild(root, parentNode, newTitle, newUrl);
                }
            }
            break;

        case 3:
            cout << "--- Cari Halaman & Jalur ---" << endl;
            cout << "Masukkan Judul Halaman yang dicari: ";
            getline(cin, newTitle);

            if (!printPagePath(root, newTitle, "")) {
                 cout << "Hasil: Halaman tidak ditemukan." << endl;
            }
            break;

        case 4:
            cout << "--- Statistik & Traversal ---" << endl;
            if (root == NULL) {
                cout << "Sitemap kosong." << endl;
            } else {
                cout << "Total Halaman : " << countTotalPages(root) << " halaman." << endl;

                cout << "\n[ Pre-Order Traversal ]" << endl;
                printPreOrder(root);
                cout << "END" << endl;

                cout << "\n[ In-Order Traversal ]" << endl;
                printInOrder(root);
                cout << "END" << endl;

                cout << "\n[ Post-Order Traversal ]" << endl;
                printPostOrder(root);
                cout << "END" << endl;
            }
            break;

        case 5:
            cout << "--- Hapus Halaman ---" << endl;
            cout << "PERINGATAN: Menghapus parent akan menghapus semua anaknya!" << endl;
            cout << "Masukkan Judul Halaman yang akan dihapus: ";
            getline(cin, newTitle);

            if (searchPage(root, newTitle) == NULL) {
                cout << "Error: Halaman tidak ditemukan." << endl;
            } else {
                deletePage(root, newTitle);
                cout << "Sukses: Halaman '" << newTitle << "' dan keturunannya telah dihapus." << endl;
            }
            break;

        case 0:
            cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
            clearScreen();
        }

    } while (pilihan != 0);

    return 0;
}
