# Foundational Data Structures in C++

This repository contains a personal exploration into the core building blocks of computer science. Implemented in C++, it documents a journey of learning fundamental data structures not just by using them, but by building them from first principles.

## About The Project

This project began as a personal challenge: to move beyond simply *using* data structures and to understand *how* they work from the ground up. Instead of relying on the standard C++ STL containers, I chose to implement each structure manually.

This "no black boxes" approach forced a deeper engagement with C++ fundamentals, including pointers, dynamic memory allocation, and the mechanics of algorithmic state management. The result is a collection of code that, while not production-ready, serves as a testament to the learning process and a deep-dive into the mechanics of data manipulation.

## Data Structures Implemented

This collection includes custom implementations of the following structures:

*   **`Dynamic Array`**: A basic implementation of a resizeable array, managing its own capacity and size.
*   **`Doubly Linked List`**: A classic linked list where each node maintains pointers to both the next and previous nodes.
*   **`Stack`**: A Last-In, First-Out (LIFO) container built upon the custom linked list implementation.
*   **`Queue`**: A First-In, First-Out (FIFO) container, also implemented using the foundational list structure.
*   **`Binary Tree`**: A custom Binary Tree implementation that includes:
    *   Logic for building a **complete binary tree**, filling each level from left to right.
    *   A suite of **iterative traversal methods** (Pre-order, In-order, Post-order, Level-order) using the custom Stack and Queue.

## Design Philosophy & Key Features

*   **From-Scratch Implementation**: Every primary data structure is built using only basic C++ primitives and pointers, without reliance on the STL. This was a deliberate choice to maximize learning.
*   **Focus on Iterative Algorithms**: A key feature is the implementation of complex algorithms like tree traversals iteratively. This was done to better understand the underlying state management that is often hidden by simpler recursive solutions.
*   **Manual Memory Management**: The code demonstrates direct engagement with C++'s memory model through the manual use of `new` and `delete`, providing a raw look at resource management.

## Getting Started

The code is organized into header files for easy inclusion. To use one of the data structures, simply include the relevant header file in your project.

**Example `main.cpp`:**

```cpp
#include <iostream>
#include "tree.hpp" // Assuming all definitions are in this header

int main() {
    // Create and use the custom tree
    tree myTree;
    myTree.add(10);
    myTree.add(5);
    myTree.add(15);
    
    std::cout << "Tree traversal:" << std::endl;
    myTree.print(); // Will prompt for traversal type

    return 0;
}