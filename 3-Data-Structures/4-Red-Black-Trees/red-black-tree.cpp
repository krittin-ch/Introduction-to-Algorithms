#include <bits/stdc++.h>

using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node* parent;
    Node* left;
    Node* right;

    Node(int val): data(val), color(RED), parent(nullptr), left(nullptr), right(nullptr) {};
};

class RBT {
    private:
        Node* root;
        Node* sentinel;

    public:
        RBT(): root(nullptr), sentinel(nullptr) {};

        void leftRotate(Node* x) {
            Node* y = x->right;
            x->right = y->left;

            if (y->left != sentinel) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            
            if (x->parent == sentinel) {
                root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void rightRotate(Node* y) {
            Node* x = y->left;
            y->left = x->right;

            if (x->right != sentinel) {
                y->left->parent = y;
            }
            x->parent = y->parent;

            if (y->parent == sentinel) {
                root = x;
            } else if (y == y->parent->left) {
                y->parent->left = x;
            } else {
                y->parent->right = x;
            }
            x->right = y;
            y->parent = x;
        }

        void RBInsert(int val) {
            Node* z = new Node(val);
            Node* x = root;
            Node* y = sentinel;

            while (x != sentinel) {
                y = x;
                if (z->data < x->data) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            z->parent = y;
            if (y == sentinel) {
                root = z;
            } else if (z->data < y->data) {
                y->left = z;
            } else {
                y->right = z;
            }
            z->left = sentinel;
            z->right = sentinel;
            z->color = RED;
            // RBInsertFixup(z);
        }

        void RBInsertFixup(Node* z) {
            while (z->parent->color == RED) {
                if (z->parent == z->parent->parent->left) {
                    Node* y = z->parent->parent->right;
                    if (y->color == RED) {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->right) {
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rightRotate(z->parent->parent);
                    }
                } else {
                    Node* y = z->parent->parent->left;
                    if (y->color == RED) {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->left) {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->color = BLACK;
        }

        Node* RBTreeSearch(Node* T, int val) {
            if (T == nullptr || T->data == val) {
                return T;
            }

            if (val < T->data) {
                return RBTreeSearch(T->left, val);
            } else {
                return RBTreeSearch(T->right, val);
            }
        }

        void RBTransplant(Node* &u, Node* &v) {
            if (u->parent == sentinel) {
                root = v;
            } else if (u == u->parent->left) {
                u->parent->left = v;
            } else {
                u->parent->right = v;
            }

            v->parent = u->parent;
        }

        Node* RBTreeMinimum() {
            Node* x = root;

            while (x->left != nullptr) {
                x = x->left;
            }

            return x;
        }

        void RBDeleteion(int val) {
            Node* z = RBTreeSearch(root, val);
            
            if (z->left == nullptr) {
                RBTransplant(z, z->right);
            } else if (z->right == nullptr) {
                RBTransplant(z, z->left);
            } else {
                Node* y = RBTreeMinimum();

                if (y != z->right) {
                    RBTransplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }

                RBTransplant(z, y);
                y->left = z->left;
                y->left->parent = y;
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

        void displayTree() {
            inorderTreeWalk(root);
            cout << endl << endl;
        }

};

int main() {
    RBT tree;

    vector<int> vec = {1, 45, 22, 2, 4, 5};

    for (int num : vec) {
        tree.RBInsert(num);
    }

    tree.displayTree();
}