#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// A Tree Node for Huffman coding
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison object for priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Function to build the Huffman Tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until the tree is complete
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        // Merge the two nodes
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

// Recursive function to generate Huffman codes
void generateHuffmanCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, store the character and its code
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to compress a string using Huffman coding
string compress(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string compressed = "";
    for (char ch : text) {
        compressed += huffmanCodes.at(ch);
    }
    return compressed;
}

// Function to calculate the frequency of each character in the input text
unordered_map<char, int> calculateFrequency(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }
    return freqMap;
}

// Function to display the Huffman codes
void displayHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    // Calculate frequency of each character
    unordered_map<char, int> freqMap = calculateFrequency(text);

    // Build Huffman Tree
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Display the Huffman codes
    displayHuffmanCodes(huffmanCodes);

    // Compress the text
    string compressed = compress(text, huffmanCodes);
    cout << "\nCompressed Text: " << compressed << endl;

    // Display compression efficiency
    int originalBits = text.size() * 8;
    int compressedBits = compressed.size();
    cout << "Original Size: " << originalBits << " bits\n";
    cout << "Compressed Size: " << compressedBits << " bits\n";
    cout << "Compression Ratio: " << (double)compressedBits / originalBits << endl;

    return 0;
}
