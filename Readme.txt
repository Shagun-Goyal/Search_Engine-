# MiniSearch – A Tiny Search Engine in Pure C 🧠

> A clean, modular, and impressive **Data Structures & Algorithms** project built entirely in **pure C**  
> Implements **Inverted Index using Binary Search Tree** + **TF-IDF Ranking** + **Phrase Search**

![MiniSearch Demo](https://via.placeholder.com/800x450.png?text=MiniSearch+Demo+Screenshot)  
*(Replace the above line with your actual screenshot)*

## Features
- Inverted Index using **Binary Search Tree** (O(log V) word lookup)
- **TF-IDF scoring** implemented from scratch for accurate ranking
- **Phrase search** supported → `"binary tree"`, `"depth first"`
- 20 built-in DSA-topic documents (hard-coded corpus)
- Case-insensitive search + punctuation removal
- Search time displayed in **microseconds**
- Top 10 ranked results (Google-style)
- Beautiful ASCII UI with colorful output
- Fully modular code (6 clean files)

## Data Structures Used
- **Binary Search Tree** → stores vocabulary and postings
- **Linked List** → inside each BST node (document list + frequency)
- Proper memory management (no leaks)

## Sample Queries
