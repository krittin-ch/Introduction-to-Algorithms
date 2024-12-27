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
        // Node* root;
        Node* sentinel;

    public:
        Node* root;
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

        void RBDeleteFixUp(Node* x) {
            while (x != root && x->color == BLACK) {
                if (x == x->parent->left) {
                    Node* w = x->parent->right;
                    
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                    }

                    if (w->left->color == BLACK && w->right->color == BLACK) {
                        w->color == RED;
                        x = x->parent;
                    } else {
                        if (w->left->color == BLACK) {
                            w->left->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->right;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        leftRotate(x->parent);
                        x = root;
                    }
                } else {
                    Node* w = x->parent->left;

                    if (w->color == RED) {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rightRotate(x->parent);
                        w = x->parent->left;
                    }

                    if (w->right->color == BLACK && x->left->color == BLACK) {
                        w->color = RED;
                        x = x->parent;
                    } else {
                        if (w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            leftRotate(w);
                            w = x->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rightRotate(x->parent);
                        x = root;
                    }
                }
            }
            x->color = BLACK;
        }

        void RBDelete(int val) {
            Node* z = RBTreeSearch(root, val);
            Node* y = z;
            Color y_original_color = y->color;
            Node* x;

            if (z->left == nullptr) {
                x = z->right;
                RBTransplant(z, z->right);
            } else if (z->right == nullptr) {
                x = z->left;
                RBTransplant(z, z->left);
            } else {
                Node* y = RBTreeMinimum();
                Color y_original_color = y->color;
                x = y->right;

                if (y != z->right) {
                    RBTransplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }

                RBTransplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }

            if (y_original_color == BLACK) {
                RBDeleteFixUp(x);
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

        void RBSubTree(Node* node, int a, int b, vector<int>& res) {
            if (!node) return;

            if (a < node->data) RBSubTree(node->left, a, b, res);
            if (a <= node->data && node->data <= b) res.push_back(node->data);
            if (b > node->data) RBSubTree(node->right, a, b, res);
        }

        void RBEnumerate(int r, int a, int b) {
            Node* subtree = RBTreeSearch(root, r);
            vector<int> res;

            RBSubTree(subtree, a, b, res);

            for (int num: res) {
                cout << num << " ";
            }
            cout << endl;
        }

        void displayTree() {
            inorderTreeWalk(root);
            cout << endl << endl;
        }

        void inorderInsert(Node* source, RBT& targetTree) {
            if (!source) return;

            inorderInsert(source->left, targetTree);
            targetTree.RBInsert(source->data);
            inorderInsert(source->right, targetTree);
        }

        RBT RBJoin(RBT T1, RBT T2) {
            if (!T2.root) return T1; 
            if (!T1.root) return T2; 

            inorderInsert(T2.root, T1);
            return T1;
        }

};

int main() {
    RBT tree_1;
    RBT tree_2;

    vector<int> vec_1 = {1, 45, 22, 2, 4, 5};
    vector<int> vec_2 = {7, 3, 21, 74, 12};
    
    for (int num : vec_1) {
        tree_1.RBInsert(num);
    }

    tree_1.displayTree();

    for (int num : vec_2) {
        tree_2.RBInsert(num);
    }

    tree_2.displayTree();

    RBT T;

    T = T.RBJoin(tree_1, tree_2);

    T.displayTree();
}