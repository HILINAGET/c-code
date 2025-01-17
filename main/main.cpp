#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


unordered_map<char, int> calculateFrequency(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }
    return freqMap;
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    // Calculate frequency of each character
    unordered_map<char, int> freqMap = calculateFrequency(text);


    return 0;
}
