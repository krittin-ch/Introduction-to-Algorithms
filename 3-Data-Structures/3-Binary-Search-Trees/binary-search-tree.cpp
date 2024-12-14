#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node(int val): data(val), parent(nullptr), left(nullptr), right(nullptr) {};
};

class BST {
    private:
        Node* root;

    public:
        BST(): root(nullptr) {};

        void treeInsert(int val) {
            Node* newNode = new Node(val);
            Node* x = root;     // node being compared with `newNode`
            Node* y = nullptr;  // `y` will be parent of `newNode`

            while (x != nullptr) {
                y = x;

                if (newNode->data < x->data) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            newNode->parent = y;

            if (y == nullptr) {
                root = newNode;
            } else if (newNode->data < y->data) {
                y->left = newNode;
            } else {
                y->right = newNode;
            }
        }

        void recursiveInsert(Node*& T, int val) {
            if (T == nullptr) {
                T = new Node(val);
                return;
            }

            if (val < T->data) {
                recursiveInsert(T->left, val);
                if (T->left != nullptr) {
                    T->left->parent = T;
                }
            } else {
                recursiveInsert(T->right, val);
                if (T->right != nullptr) {
                    T->right->parent = T;
                }
            }

            return;
        }

        void recursiveTreeInsert(int val) {
            recursiveInsert(root, val);
        }

        Node* treeSearch(Node* T, int val) {
            Node* x = T;

            if (x == nullptr || x->data == val) {
                return x;
            }

            if (val < x->data) {
                return treeSearch(T->left, val);
            } else {
                return treeSearch(T->right, val);
            }
        }

        Node* iterativeTreeSearch(Node* T, int val) {
            Node* x = T;
            
            while (x != nullptr && val != x->data) {
                if (val < x->data) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            return x;
        }

        Node* treeMinimum(Node* T) {
            Node* x = T;

            while (x->left != nullptr) {
                x = x->left;
            }

            return x;
        }

        Node* treeMaximum(Node* T) {
            Node* x = T;

            while (x->right != nullptr) {
                x = x->right;
            }

            return x;
        }

        Node* treeSuccessor(Node* T) {
            Node* x = T;

            if (x->right != nullptr) {
                return treeMinimum(x->right);
            } else {
                Node* y = x->parent;

                while (y != nullptr && x == y->right) {
                    x = y;
                    y = y->parent;
                }

                return y;
            }
        }

        void transplant(Node* &u, Node* &v) {
            if (u->parent == nullptr) {
                root = v;
            } else if (u == u->parent->left) {
                u->parent->left = v;
            } else {
                u->parent->right = v;
            }

            if (v != nullptr) {
                v->parent = u->parent;
            }
        }

        void treeDeletion(int val) {
            Node* z = treeSearch(root, val);
            if (z == nullptr) {
                cout << "Value not found in the tree.\n";
                return;
            }

            // Case 1: No left child
            if (z->left == nullptr) {
                transplant(z, z->right);
            }
            // Case 2: No right child
            else if (z->right == nullptr) {
                transplant(z, z->left);
            }
            // Case 3: Two children
            else {
                Node* y = treeMinimum(z->right);
                if (y->parent != z) {
                    transplant(y, y->right);
                    y->right = z->right;   // Use assignment operator
                    y->right->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
            }

            delete z;  // Don't forget to delete the removed node
        }


        void preorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                cout << x->data << " ";
                preorderTreeWalk(x->left);
                preorderTreeWalk(x->right);
            }
        }

        void inorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                inorderTreeWalk(x->left);
                cout << x->data << " ";
                inorderTreeWalk(x->right);
            }
        }

        void inorderTreeWalkWithStack() {
            stack<Node*> stk;
            Node* x  = root;

            while (x != nullptr || stk.empty() == false) {
                while (x != nullptr) {
                    stk.push(x);
                    x = x->left;
                }

                x = stk.top();
                stk.pop();
                cout << x->data << " ";

                x = x->right;                
            }
        }

        vector<int> MorrisTraversal() {    // using 2 pointers
            vector<int> res;
            Node* curr  = root;

            while (curr != nullptr) {
                if (curr->left == nullptr) {
                    res.push_back(curr->data);
                    curr = curr->right;
                } else {
                    Node* prev = curr->left;
                    while (prev->right != nullptr && prev->right != curr) {
                        prev = prev->right;
                    }

                    if (prev->right == nullptr) {
                        prev->right = curr;
                        curr = curr->left;
                    } else {
                        prev->right = nullptr;
                        res.push_back(curr->data);
                        curr = curr->right;
                    }
                }
            }
            return res;
        }

        void alternativeInorderTreeWalk() {
            Node* x = treeMinimum(root);

            while (x != nullptr) {
                cout << x->data << " ";
                x = treeSuccessor(x);
            }
        }

        void displayMorris() {
            vector<int> seq = MorrisTraversal();

            for (int num : seq) {
                cout << num << " ";
            }
        }

        void postorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                postorderTreeWalk(x->left);
                postorderTreeWalk(x->right);
                cout << x->data << " ";
            }
        }

        void displayTree(int type) {
            if (type == 0) {
                preorderTreeWalk(root);
            } else if (type == 1) {
                inorderTreeWalk(root);
            } else if (type == 2) {
                postorderTreeWalk(root);
            } else if (type == 3) {
                inorderTreeWalkWithStack();
            } else if (type == 4) {
                displayMorris();
            } else if (type == 5) {
                alternativeInorderTreeWalk();
            }

            cout << endl << endl;
        }

};

int main() {
    BST tree;

    vector<int> vec = {20, 10, 26, 4, 18, 24, 27, 14, 19, 13, 15};

    for (int i : vec) {
        // tree.treeInsert(i);
        tree.recursiveTreeInsert(i);
    }

    cout << "Preorder Traversal : ";
    tree.displayTree(0);
    cout << "Postorder Traversal : ";
    tree.displayTree(2);
    cout << "Inorder Traversal : ";
    tree.displayTree(1);
    cout << "Inorder Traversal with Stack: ";
    tree.displayTree(3);
    cout << "Morris Traversal: ";
    tree.displayTree(4);   
    cout << "Alternative Inorder Traversal: ";
    tree.displayTree(5);

    tree.treeDeletion(13);
    cout << "Delete 13: ";
    tree.displayTree(5);

    return 0;
}