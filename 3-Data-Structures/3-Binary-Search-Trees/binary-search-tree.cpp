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
    private :
        Node* root;

    public :
        BST(): root(nullptr) {};

        void TreeInsert(int val) {
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

        Node* TreeSearch(Node* T, int val) {
            Node* x = T;

            if (x != nullptr || x->data != val) {
                return x;
            }

            if (val < x->data) {
                return TreeSearch(T->left, val);
            } else {
                return TreeSearch(T->right, val);
            }
        }

        Node* IterativeTreeSearch(Node* T, int val) {
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

        Node* TreeMinimum(Node* T) {
            Node* x = T;

            while (x->left != nullptr) {
                x = x->left;
            }

            return x;
        }

        Node* TreeMaximum(Node* T) {
            Node* x = T;

            while (x->right != nullptr) {
                x = x->right;
            }

            return x;
        }

        Node* TreeSuccessor() {
            Node* x = root;

            if (x->right != nullptr) {
                return TreeMinimum(x->right);
            } else {
                Node* y = x->parent;

                while (y != nullptr && x == y->right) {
                    x = y;
                    y = y->parent;
                }

                return y;
            }
        }

        // void Transplant(Node* &T, Node* &u, Node* &v) {
        //     if (u->parent == nullptr) {
        //         T = v;
        //     } else if (u == u->parent->left) {
        //         u->parent->left = v;
        //     } else {
        //         u->parent->right = v;
        //     }

        //     if (v != nullptr) {
        //         v->parent = u->parent;
        //     }
        // }

        // void TreeDeletion(Node* &T, int val) {
        //     Node* z = new Node(val);
        //     if (z->left)
        // }

        void PreorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                cout << x->data << " ";
                PreorderTreeWalk(x->left);
                PreorderTreeWalk(x->right);
            }
        }

        void InorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                InorderTreeWalk(x->left);
                cout << x->data << " ";
                InorderTreeWalk(x->right);
            }
        }

        void PostorderTreeWalk(Node* T) {
            Node* x = T;

            if (x != nullptr) {
                PostorderTreeWalk(x->left);
                PostorderTreeWalk(x->right);
                cout << x->data << " ";
            }
        }

        void displayTree(int type) {
            if (type < 0) {
                PreorderTreeWalk(root);
            } else if (type == 0) {
                InorderTreeWalk(root);
            } else {
                PostorderTreeWalk(root);
            }
            cout << endl << endl;
        }

};

int main() {
    BST tree;

    vector<int> vec = {20, 10, 26, 4, 18, 24, 27, 14, 19, 13, 15};

    for (int i : vec) {
        tree.TreeInsert(i);
    }

    cout << "Preorder Traversal : ";
    tree.displayTree(-1);
    cout << "Inorder Traversal : ";
    tree.displayTree(0);
    cout << "Postorder Traversal : ";
    tree.displayTree(1);
    
    return 0;
}