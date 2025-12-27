#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct WebPage {
    string title;
    string url;
};

typedef struct Node *adr;

struct Node {
    WebPage info;
    adr firstChild;
    adr nextSibling;
};

// Kamus Operasi
// 1. Pembuatan & Penambahan
adr createNode(string title, string url);
void addChild(adr root, adr parent, string title, string url);

// 2. Penghapusan
void deleteTree(adr &P);
void findAndDisconnect(adr parent, string targetTitle);
void deletePage(adr &root, string targetTitle);

// 3. Penelusuran (Traversal)
void printSitemap(adr root, int indent = 0);
void printPreOrder(adr root);
void printPostOrder(adr root);
void printInOrder(adr root);

// 4. Informasi & Pencarian
adr searchPage(adr root, string targetTitle);
adr searchByURL(adr root, string targetURL);
bool printPagePath(adr root, string targetTitle, string currentPath = "");
int countTotalPages(adr root);

#endif // HEADER_H_INCLUDED
