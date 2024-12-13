#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* top;
    Node* left;
    Node* right;

    Node(int val) : data(val), top(nullptr), left(nullptr), right(nullptr) {};
};

struct searchResult {
    Node* node;
    int height;
};

class BinaryTree {
    private:
        Node* root;
    
    public:
        BinaryTree() : root(nullptr) {};

        // return a parent node containing only one or no child
        searchResult findEmpty(Node* root, int height) {
            if (root == nullptr) {
                return {nullptr, 0};
            }

            if (root->left == nullptr || root->right == nullptr) {
                return {root, height};
            }

            height++;

            searchResult left = findEmpty(root->left, height);
            searchResult right = findEmpty(root->right, height);

            if (left.height <= right.height) {
                return left;
            } else {
                return right;
            }
        }

        void insert(int val) {
            Node* newNode = new Node(val);
            
            if (root == nullptr) {
                root = newNode;
                return;
            }

            searchResult parent = findEmpty(root, 0);
            

            if (parent.node->left == nullptr) {
                parent.node->left = newNode;
                newNode->top = parent.node;
            } else {
                parent.node->right = newNode;
                newNode->top = parent.node;
            }
        }

        void displayPreOrderTraversal(Node* root) {
            if (root == nullptr) {
                return;
            }

            cout << root->data << " ";

            displayPreOrderTraversal(root->left);
            displayPreOrderTraversal(root->right);
        }

        void displayPreOrderTraversalIterative(Node* root) {
            if (root == nullptr) {
                return;
            }

            stack<Node*> nodeStack;
            nodeStack.push(root);

            while (!nodeStack.empty()) {
                Node* currentNode = nodeStack.top();
                nodeStack.pop();

                cout << currentNode->data << " ";

                // Push right child first so that left child is processed first
                if (currentNode->right) {
                    nodeStack.push(currentNode->right);
                }
                if (currentNode->left) {
                    nodeStack.push(currentNode->left);
                }
            }
        }

        void display() {
            displayPreOrderTraversal(root);
            cout << endl;
            displayPreOrderTraversalIterative(root);
            cout << endl;
        }
};

int main() {
    BinaryTree bt;

    for (int i = 0; i < 10; i++) {
        bt.insert(i);
        // bt.display();
    }

    bt.display();
    return 0;
}

/*
                0
      1                 2
  3         4       5       6
7   8   9
*/