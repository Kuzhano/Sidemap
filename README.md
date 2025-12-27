# Sitemap Generator: N-ary Tree Implementation
> **A robust C++ solution for hierarchical web structure management using General Tree structures.**

[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-General%20Tree-orange)](https://en.wikipedia.org/wiki/Tree_(data_structure))
[![Academic](https://img.shields.io/badge/Academic-Project-red)](#academic-context)

## Overview
This project implements a **General Tree (N-ary Tree)** using the **First Child - Next Sibling** representation. It is specifically designed to handle real-world scenarios like web sitemaps where a parent node can have an unlimited number of children.

---

## Key Features
* **Dynamic Hierarchy:** Add unlimited sub-pages to any parent node without fixed child limits.
* **Unique URL Validation:** Integrated safety check to prevent duplicate URLs across the entire sitemap.
* **Breadcrumb Pathfinding:** Recursive path generation that displays the full URL string from Root to any target.
* **Full Traversal Suite:** Supports **Pre-Order**, **In-Order**, and **Post-Order** traversals to meet theoretical requirements.
* **Safe Memory Cleanup:** Recursive post-order deletion ensures no memory leaks when removing nodes or entire sub-trees.

---

## Data Structure Anatomy
The project utilizes a **Multi-Linked List** approach to represent a **General Tree**. Every node contains:
* `WebPage info`: Title and unique URL.
* `firstChild`: Pointer to the first child (downwards hierarchy).
* `nextSibling`: Pointer to the next sibling (horizontal hierarchy).



---

## Traversal Logic Analysis
As per the academic requirements, the system demonstrates three primary traversals:

| Traversal | Logic Flow | Use Case |
| :--- | :--- | :--- |
| **Pre-Order** | Root $\rightarrow$ Child $\rightarrow$ Sibling | Visualizing site hierarchy  |
| **In-Order** | First Child $\rightarrow$ Root $\rightarrow$ Siblings | Specific internal node processing |
| **Post-Order** | Children $\rightarrow$ Root | Safe memory deallocation/deletion |

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
