# Huffman Coding for Data Compression
# Repository Setup Guide


## Prerequisites

Before starting, ensure you have the following:
- A Windows, Linux, or macOS system.
- Administrator privileges to install software.

---

## Step 1: Install Code::Blocks

### Windows
1. Download the Code::Blocks installer with the MinGW compiler:
   - [Download Link](https://www.codeblocks.org/downloads/)
   - Choose the version labeled **"codeblocks-XX.Xmingw-setup.exe"**.


## Step 2: Clone the Repository

1. Open a terminal (or Command Prompt on Windows).
2. Clone this repository:
   

## Overview

Huffman coding is a lossless data compression algorithm that assigns variable-length binary codes to characters based on their frequencies. Characters with higher frequencies are assigned shorter codes, while those with lower frequencies get longer codes. This approach ensures efficient compression of text data.

This project implements Huffman coding in C++ to compress text data. It demonstrates the use of:
- **Priority Queue (Min-Heap)** for constructing the Huffman tree.
- **Binary Tree** to store characters and their corresponding frequencies.
- Encoding and decoding mechanisms for text compression.

## Features

- Calculates the frequency of each character in the input text.
- Constructs a Huffman tree using a priority queue.
- Generates binary codes for characters based on their frequencies.
- Encodes the input text into a compressed binary format.
- Demonstrates the efficiency of the Huffman coding algorithm.

---

## Problem Statement

Create a C++ program to implement Huffman coding for compressing text data. Discuss the choices made in terms of data structures (e.g., priority queues) and the efficiency of the compression achieved.

**Key Requirements:**
1. Use a priority queue to manage character frequencies.
2. Build a binary tree to assign variable-length codes to characters.
3. Encode a given input text using the generated Huffman codes.
4. Ensure the implementation is efficient and produces accurate results.

---

## Implementation Details

### **Data Structures**

1. **Priority Queue (Min-Heap):**
   - Used to efficiently extract the two nodes with the smallest frequencies.
   - Ensures optimal construction of the Huffman tree.

2. **Binary Tree (Huffman Tree):**
   - Each leaf node represents a character.
   - Internal nodes store combined frequencies of their child nodes.

---

### **Algorithm**

1. **Frequency Calculation:**
   Count the frequency of each character in the input text.

2. **Tree Construction:**
   - Insert all characters and their frequencies into a priority queue.
   - Repeatedly extract two nodes with the smallest frequencies and merge them into a new internal node.
   - Continue until only one node (the root) remains in the priority queue.

3. **Code Assignment:**
   - Perform a depth-first traversal of the Huffman tree.
   - Assign binary codes (0 for left, 1 for right) to each character.

4. **Text Encoding:**
   - Replace each character in the input text with its corresponding Huffman code.

---

### **Code**

```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the structure for the Huffman Tree Node
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Define the comparator for the priority queue (min-heap)
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& freqTable) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a node for each character and insert into the priority queue
    for (auto pair : freqTable) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }

    // The remaining node is the root of the Huffman tree
    return minHeap.top();
}

// Function to generate the Huffman codes for each character
void generateHuffmanCodes(Node* root, string str, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) return;

    // If we reach a leaf node, store the code
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->character] = str;
    }

    // Traverse left and right subtrees and append 0 or 1 to the code
    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

// Function to encode the text using Huffman codes
string encodeText(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes.at(c);
    }
    return encodedText;
}

int main() {
    // Input text data
    string text = "this is an example for huffman encoding";

    // Step 1: Calculate frequency of each character
    unordered_map<char, int> freqTable;
    for (char c : text) {
        freqTable[c]++;
    }

    // Step 2: Build the Huffman Tree
    Node* root = buildHuffmanTree(freqTable);

    // Step 3: Generate Huffman codes for each character
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Step 4: Print the Huffman codes
    cout << "Huffman Codes:" << endl;
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Step 5: Encode the text
    string encodedText = encodeText(text, huffmanCodes);
    cout << "\nEncoded Text: " << encodedText << endl;

    return 0;
}
---

## Group Memeber
| #  | NAME                   | ID            |
|----|------------------------|---------------|
| 1  | Hilina Getahun          | NSR/1282/13   |
| 2  | Tsigereda Ojige         | NSR/2371/13   |
| 3  | Oli Chimdessa           | NSR/1928/13   |
| 4  | Cheramilak Mengstu      | NSR/686/13    |
| 5  | Addisu Belane           | NSR/163/13    |
