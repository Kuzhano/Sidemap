# Sitemap Generator: N-ary Tree Implementation
> **A robust C++ solution for hierarchical web structure management using General Tree structures.**

[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-General%20Tree-orange)](https://en.wikipedia.org/wiki/Tree_(data_structure))
[![Academic](https://img.shields.io/badge/Academic-Project-red)](#academic-context)

## Overview
[cite_start]This project implements a **General Tree (N-ary Tree)** using the **First Child - Next Sibling** representation[cite: 4, 38]. [cite_start]It is specifically designed to handle real-world scenarios like web sitemaps where a parent node can have an unlimited number of children[cite: 6, 8].

---

## Key Features
* [cite_start]**Dynamic Hierarchy:** Add unlimited sub-pages to any parent node without fixed child limits[cite: 13, 22].
* **Unique URL Validation:** Integrated safety check to prevent duplicate URLs across the entire sitemap.
* [cite_start]**Breadcrumb Pathfinding:** Recursive path generation that displays the full URL string from Root to any target[cite: 24, 25].
* [cite_start]**Full Traversal Suite:** Supports **Pre-Order**, **In-Order**, and **Post-Order** traversals to meet theoretical requirements[cite: 12, 23, 39].
* [cite_start]**Safe Memory Cleanup:** Recursive post-order deletion ensures no memory leaks when removing nodes or entire sub-trees[cite: 13, 24].

---

## Data Structure Anatomy
The project utilizes a **Multi-Linked List** approach to represent a **General Tree**. Every node contains:
* [cite_start]`WebPage info`: Title and unique URL[cite: 17, 20].
* `firstChild`: Pointer to the first child (downwards hierarchy).
* `nextSibling`: Pointer to the next sibling (horizontal hierarchy).



---

## Traversal Logic Analysis
[cite_start]As per the academic requirements, the system demonstrates three primary traversals[cite: 12, 23, 39]:

| Traversal | Logic Flow | Use Case |
| :--- | :--- | :--- |
| **Pre-Order** | Root $\rightarrow$ Child $\rightarrow$ Sibling | [cite_start]Visualizing site hierarchy [cite: 12] |
| **In-Order** | First Child $\rightarrow$ Root $\rightarrow$ Siblings | [cite_start]Specific internal node processing [cite: 12] |
| **Post-Order** | Children $\rightarrow$ Root | [cite_start]Safe memory deallocation/deletion [cite: 12] |

---

## Sample Program Output
When running the application, the hierarchical sitemap is visualized as follows:

```text
=======================================
======= GENERAL TREE SITEMAP GEN ======
=======================================
[ Struktur Website Saat Ini ]
|-- Home (/home)
    |-- Profil (/profile)
        |-- Sejarah (/history)
        |-- Visi Misi (/vision)
    |-- Produk (/products)
        |-- Elektronik (/electronics)
        |-- Fashion (/fashion)
    |-- Berita (/news)

Total Halaman : 7 halaman.
