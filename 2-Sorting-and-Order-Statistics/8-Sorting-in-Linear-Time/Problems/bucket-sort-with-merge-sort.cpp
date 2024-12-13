#include <bits/stdc++.h>

using namespace std;

class Node {
    private:
        float data;
        Node* next;
    
    public:
        Node(float val) {
            data = val;
            next = nullptr;
        }

        float getData() const {
            return data;
        }

        Node* getNext() const {
            return next;
        }

        void setNext(Node* newNode) {
            next = newNode;
        }

        void setData(float newVal) {
            data = newVal;
        }
};

class LinkedList {
    private:
        Node* head;

        void split(Node* source, Node* &frontRef, Node* &backRef) {
            Node* slow = source;
            Node* fast = source->getNext();

            while (fast != nullptr) {
                fast = fast->getNext();
                if (fast != nullptr) {
                    fast = fast->getNext();
                    slow = slow->getNext();
                }
            }

            frontRef = source;
            backRef = slow->getNext();
            slow->setNext(nullptr);
        }

        Node* merge_original(Node* left, Node* right) {
            if (left == nullptr) return right;
            if (right == nullptr) return left;

            Node dummy(0);  // Stack Allocation and the destructor is called automatically when the object is unused
            Node* res = &dummy;
            Node* current = &dummy;
            
            /*
            Or

            // Heap Allocation and the destructor is not called automatically when the object is unused
            // The user have to manually call the destructor to create memory efficient system
            Node* dummy = new Node(0);
            Node res = dummy;
            Node current = dummy;
            */

            while (left != nullptr && right != nullptr) {
                if (left->getData() < right->getData()) {
                    current->setNext(left);
                    current = current->getNext();
                    left = left->getNext();
                } else {
                    current->setNext(right);
                    right = right->getNext();
                }
            }

            while (left != nullptr) {
                current->setNext(left);
                current = current->getNext();
                left = left->getNext();
            }

            while (right != nullptr) {
                current->setNext(right);
                current = current->getNext();
                right = right->getNext();
            }

            return res->getNext();
        }

        Node* merge(Node* left, Node* right) {
            if (left == nullptr) return right;
            if (right == nullptr) return left;

            Node* res = nullptr;

            if (left->getData() < right->getData()) {
                res = left;
                res->setNext(merge(left->getNext(), right));
            } else {
                res = right;
                res->setNext(merge(left, right->getNext()));
            }

            return res;
        }

        Node* mergeSort(Node* headRef) {
            if (headRef == nullptr || headRef->getNext() == nullptr) {
                return headRef;
            }

            Node* front = nullptr;
            Node* back = nullptr;

            split(headRef, front, back);

            front = mergeSort(front);
            back = mergeSort(back);

            return merge(front, back);
        }

    public:
        LinkedList() : head(nullptr) {};

        void insert(float val) {
            Node* newNode = new Node(val);
            newNode->setNext(head);
            head = newNode;
        }

        void displayLinkedList() {
            Node* temp = head;
            
            while (temp != nullptr) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }

        void sort() {
            head = mergeSort(head);
        }
        
        void copyToVector(vector<float> &vec) {
            Node* temp = head;

            while (temp != nullptr) {
                vec.push_back(temp->getData());
                temp = temp->getNext();
            }
        }
};

void bucketSort(vector<float> &vec) {
    vector<LinkedList> bucket(10);

    for (float num : vec) {
        int idx = 10 * num;
        bucket[idx].insert(num);
    }

    vec.clear();
    // for (LinkedList &ls : bucket) { ... }
    // &ls is a reference to the actual object in the bucket
    
    // for (LinkedList ls : bucket) { ... } 
    // ls is a copy of each "LinkedList" object from the bucket
    
    for (LinkedList &ls : bucket) {
        ls.sort();
        ls.copyToVector(vec);
    }
}

void displayArray(vector<float> vec) {
    for (float num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<float> vec = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original Array : " << endl;
    displayArray(vec);

    bucketSort(vec);
    cout << "Sorted Array : " << endl;
    displayArray(vec);

    return 0;
}