# Huffman Coding for Data Compression

# Screenshots

![](https://github.com/HILINAGET/c-code/blob/main/image/image.png?raw=true)


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

# Huffman Coding Implementation

This repository contains an implementation of Huffman Coding in C++. Huffman Coding is a lossless data compression algorithm that uses variable-length codes to represent characters based on their frequencies in the input data.

## Code Explanation

### Header Files
- `#include <iostream>`: For input and output operations.
- `#include <queue>`: To use the priority queue for building the Huffman Tree.
- `#include <unordered_map>`: For mapping characters to their frequencies and codes.
- `#include <vector>`: For the vector container used by the priority queue.
- `#include <string>`: To handle text data.

### Key Structures and Functions

#### 1. **`HuffmanNode` Structure**
- The HuffmanNode structure typically consists of value, frequency, left child and right child. by combining these attributes within      the HuffmanNode structure, we can create an effective representation of nodes in the Huffman tre.
- Allowing for optimized data compression and decompression operations..
- Members:
  - `char ch`: Character.
  - `int freq`: Frequency of the character.
  - `HuffmanNode* left, * right`: Pointers to left and right child nodes.
- Constructor initializes the character, frequency, and child pointers.

#### 2. **`Compare` Struct**
- Defines the comparison logic for the priority queue.
- Ensures that the node with the smallest frequency has the highest priority.

#### 3. **`buildHuffmanTree` Function**
- Input: A frequency map (`unordered_map<char, int>`).
- Steps:
  1. Create a priority queue of `HuffmanNode` pointers.
  2. Push a node for each character-frequency pair into the queue.
  3. Repeatedly merge the two lowest-frequency nodes until one node remains (the root of the tree).
- Output: The root of the Huffman Tree.

#### 4. **`generateHuffmanCodes` Function**
- Input: Root of the Huffman Tree, current code string, and a map to store codes.
- Recursively traverses the tree to generate binary codes for each character.
- Assigns `0` for left branches and `1` for right branches.

#### 5. **`compress` Function**
- Input: Text string and Huffman Codes.
- Converts the input text into a binary string using the generated codes.
- Output: Compressed binary string.

#### 6. **`calculateFrequency` Function**
- Input: Text string.
- Counts the frequency of each character in the text.
- Output: A frequency map.

#### 7. **`displayHuffmanCodes` Function**
- Input: Map of Huffman Codes.
- Prints the character-to-code mapping.

### Main Function Workflow
1. Takes input text from the user.
2. Calculates the frequency of each character using `calculateFrequency`.
3. Builds the Huffman Tree using `buildHuffmanTree`.
4. Generates Huffman Codes using `generateHuffmanCodes`.
5. Displays the Huffman Codes with `displayHuffmanCodes`.
6. Compresses the input text using `compress` and prints the compressed output.
7. Displays compression statistics (original size, compressed size, and compression ratio).

### Example Input and Output
#### Input:
```
Enter text to compress: hello huffman
```
#### Output:
```
Huffman Codes:
h: 00
e: 01
l: 10
 : 110
u: 1110
f: 1111
m: 1000
n: 1001

Compressed Text: 00101010011011101111111110001001
Original Size: 112 bits
Compressed Size: 36 bits
Compression Ratio: 0.321429
```



```

## Group Memeber
| #  | NAME                   | ID            |
|----|------------------------|---------------|
| 1  | Hilina Getahun          | NSR/1282/13   |
| 2  | Tsigereda Ojige         | NSR/2371/13   |
| 3  | Oli Chimdessa           | NSR/1928/13   |
| 4  | Cheramilak Mengstu      | NSR/686/13    |
| 5  | Addisu Beyene           | NSR/163/13    |
