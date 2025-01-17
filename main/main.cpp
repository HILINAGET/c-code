#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>

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


    for (auto pair : freqTable) {
        minHeap.push(new Node(pair.first, pair.second));
    }


    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }


    return minHeap.top();
}

// Function to generate the Huffman codes for each character
void generateHuffmanCodes(Node* root, string str, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) return;


    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->character] = str;
    }


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

// Function to print the Huffman codes
void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    // Input text data
    string text = "this is an example for huffman encoding";

    //  Calculate frequency of each character
    unordered_map<char, int> freqTable;
    for (char c : text) {
        freqTable[c]++;
    }

    //  Build the Huffman Tree
    Node* root = buildHuffmanTree(freqTable);

    //  Generate Huffman codes for each character
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    //  Print the Huffman codes
    cout << "Huffman Codes:" << endl;
    printHuffmanCodes(huffmanCodes);

    // Encode the text
    string encodedText = encodeText(text, huffmanCodes);
    cout << "\nEncoded Text: " << encodedText << endl;

    return 0;
}
