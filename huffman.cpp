#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        if (left->frequency == right->frequency) {
            return left->character > right->character;
        }
        return left->frequency > right->frequency;
    }
};

void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (const auto& entry : freq) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    cout << "Character Huffman Codes:\n";
    for (const auto& entry : huffmanCodes) {
        cout << "\"" << entry.first << "\": " << entry.second << endl;
    }
}

int main() {
    string input = "beep boop beer!";

    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    cout << "Frequencies of characters:\n";
    for (const auto& entry : freq) {
        cout << "\"" << entry.first << "\": " << entry.second << endl;
    }

    Node* root = buildHuffmanTree(freq);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    printHuffmanCodes(huffmanCodes);

    return 0;
}