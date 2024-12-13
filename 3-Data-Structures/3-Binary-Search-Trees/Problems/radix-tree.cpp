#include <bits/stdc++.h>

using namespace std;

class RadixTree {
    private :
        struct  Node {
            Node* left;
            Node* right;
            bool isEnd;

            Node(): left(nullptr), right(nullptr), isEnd(false) {}
        };

        Node* root;

    public:
        RadixTree(): root(new Node()) {}
};

/*
#include <iostream>
#include <string>
#include <vector>

class RadixTree {
private:
    struct Node {
        Node* left;   // child for '0'
        Node* right;  // child for '1'
        bool isEnd;   // marks end of a string

        Node() : left(nullptr), right(nullptr), isEnd(false) {}
    };

    Node* root;

public:
    RadixTree() : root(new Node()) {}

    // Insert a bit string into the radix tree
    void insert(const std::string& bitString) {
        Node* current = root;
        for (char c : bitString) {
            if (c == '0') {
                if (!current->left) {
                    current->left = new Node();
                }
                current = current->left;
            } else { // c == '1'
                if (!current->right) {
                    current->right = new Node();
                }
                current = current->right;
            }
        }
        current->isEnd = true;
    }

    // Print all strings in lexicographic order
    void printSorted() const {
        std::string prefix;
        printSortedHelper(root, prefix);
    }

    ~RadixTree() {
        clear(root);
    }

private:
    // Recursive helper for printing in lex order
    void printSortedHelper(Node* node, std::string& prefix) const {
        if (!node) return;

        // If this node marks the end of a string, print it
        if (node->isEnd) {
            std::cout << prefix << "\n";
        }

        // Explore '0' branch first
        if (node->left) {
            prefix.push_back('0');
            printSortedHelper(node->left, prefix);
            prefix.pop_back();
        }

        // Then explore '1' branch
        if (node->right) {
            prefix.push_back('1');
            printSortedHelper(node->right, prefix);
            prefix.pop_back();
        }
    }

    // Utility to free memory
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

int main() {
    // Example usage:
    RadixTree tree;
    std::vector<std::string> S = {"1011", "10", "011", "100", "0"};
    for (auto &s : S) {
        tree.insert(s);
    }

    // Print in lexicographic order
    tree.printSorted();

    return 0;
}

*/