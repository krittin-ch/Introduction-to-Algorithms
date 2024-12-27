#include <bits/stdc++.h>

using namespace std;

class RadixTree {
    private:
        struct  Node {
            Node* left;
            Node* right;
            bool isEnd;

            Node(): left(nullptr), right(nullptr), isEnd(false) {}
        };

        Node* root;

    public:
        RadixTree(): root(new Node()) {}

        void insert(const string& bitString) {
            Node* curr = root;
            for (char c : bitString) {
                if (c == '0') {
                    if (!curr->left) {  // check if curr->left == nullptr
                        curr->left = new Node();
                    }
                    curr = curr->left;
                } else { // c == '1'
                    if (!curr->right) { // check if curr->right == nullptr
                        curr->right = new Node();
                    }
                    curr = curr->right;
                }
            }
            curr->isEnd = true;
        }

        void printSorted() {
            string prefix;
            printSortedHelper(root, prefix);
        }

    private:
        void printSortedHelper(Node* node, string& prefix) {
        
        /*
        Consider a tree with the following structure and end nodes:

                (root)
                /    \
            (0)    (1)
            /  \    /  \
        (0)  (1) (0)  (1)
            \    \ 
            (1)  (1)

        Imagine the "end" nodes are located at these paths:
        - Left->Left->Right = 0 0 1
        - Left->Right->Right = 0 1 1
        - Right->Left = 1 0

        We want to print these paths: "001", "011", and "10".


        Steps showing how prefix changes:

        Start with prefix = "".

        Explore left subtree (push '0'): prefix = "0"
        Explore left subtree (push '0'): prefix = "00"
            Explore right subtree (push '1'): prefix = "001" 
            It's an end node, print "001"
            Return from right: pop_back() => prefix = "00"
            Done with left->left->right, now return: pop_back() => prefix = "0"

        Explore right subtree (push '1'): prefix = "01"
            Explore right subtree (push '1'): prefix = "011"
            It's an end node, print "011"
            Return from right: pop_back() => prefix = "01"
            Done with left->right->right, return: pop_back() => prefix = "0"

        Done exploring left subtree, return: pop_back() => prefix = ""


        Explore right subtree (push '1'): prefix = "1"
        Explore left subtree (push '0'): prefix = "10"
            It's an end node, print "10"
            Return: pop_back() => prefix = "1"
        Done right->left, return: pop_back() => prefix = ""


        Every push_back('0' or '1') to explore a subtree is paired with a pop_back()
        after returning, ensuring prefix always matches the current path.
        */

            if (!node) return;

            if (node->isEnd) {
                cout << prefix << " ";
            }

            if (node->left) {   // check if node->left != nullptr
                prefix.push_back('0');
                printSortedHelper(node->left, prefix);
                prefix.pop_back();
            } 
            
            if (node->right) {   // check if node->right != nullptr
                prefix.push_back('1');
                printSortedHelper(node->right, prefix);
                prefix.pop_back();
            }
        }

};

int main() {
    RadixTree tree;
    std::vector<std::string> S = {"1011", "10", "011", "100", "0"};
    for (auto &s : S) {
        tree.insert(s);
    }

    // Print in lexicographic order
    tree.printSorted();

    return 0;
}