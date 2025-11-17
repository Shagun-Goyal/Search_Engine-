#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#define TOTAL_DOCS 20

const char *doc_titles[TOTAL_DOCS] = {
    "Introduction to Data Structures",
    "Arrays and Linked Lists",
    "Stacks and Quees Implementation",
    "Binary Trees Explained",
    "Binary Search Tree Operations",
    "AVL Trees and Balancing",
    "Graph Theory Basics",
    "Depth First Search Algorithm",
    "Breadth First Search in Graphs",
    "Dijkstra Shortest Path Algorithm",
    "Hashing and Hash Tables",
    "Heap and Priority Queue",
    "Sorting Algorithms Comparison",
    "Quick Sort and Merge Sort",
    "Dynamic Programming Concepts",
    "Greedy Algorithms Overview",
    "Backtracking and N-Queen Problem",
    "Trie Data Structure",
    "Segment Trees and Fenwick",
    "Operating System Scheduling"
};

const char *doc_contents[TOTAL_DOCS] = {
    "Data structures are fundamental building blocks. Arrays and linked lists are basic.",
    "Arrays provide fast access. Linked lists allow dynamic memory allocation and easy insertion.",
    "Stacks follow LIFO. Queues follow FIFO principle in data processing.",
    "Binary trees have at most two children. They are used in many algorithms.",
    "Binary search tree maintains sorted order. Left child is smaller, right is larger.",
    "AVL trees are self-balancing binary search trees. Rotations maintain height balance.",
    "Graphs consist of vertices and edges. They model real-world networks.",
    "Depth first search explores as far as possible along each branch before backtracking.",
    "Breadth first search explores level by level using a queue data structure.",
    "Dijkstra algorithm finds shortest path in weighted graphs with non-negative weights.",
    "Hashing maps data to fixed-size table. Hash tables provide average O(1) operations.",
    "Heap is a complete binary tree. Priority queue is implemented using heap.",
    "Sorting algorithms include bubble, insertion, selection, quick and merge sort.",
    "Quick sort chooses pivot and partitions. Merge sort divides and conquers.",
    "Dynamic programming solves overlapping subproblems with memoization technique.",
    "Greedy algorithms make locally optimal choice hoping for global optimum.",
    "Backtracking tries different possibilities and undoes when failure occurs.",
    "Trie is prefix tree used for fast string retrieval and autocomplete.",
    "Segment trees handle range queries efficiently in logarithmic time.",
    "Operating system uses scheduling algorithms like FCFS, SJF and Round Robin."
};

#endif