#include <bits/stdc++.h>

using namespace std;

struct Node {
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {}
};

class LinkedList {
    private :
        Node* head; 

        Node* sortedInsertion(Node* headRef, Node* newNode) {
            if (headRef == nullptr || headRef->data > newNode->data) {
                newNode->next = headRef;
                return newNode;
            }

            Node* current = headRef;
            
            while (current->next != nullptr && current->next->data < newNode->data) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;

            return headRef;
        }

        Node* sortedMerge(Node* left, Node* right) {
            if (left == nullptr) return right;
            if (right == nullptr) return left;

            Node* result = nullptr;
            
            if (left->data < right->data) {
                result = left;
                result->next = sortedMerge(left->next, right);
            } else {
                result = right;
                result->next = sortedMerge(left, right->next);
            }

            return result;

        }

    public :
        LinkedList() : head(nullptr) {}

        void insert(float val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        
        void displayLinkedList() {
            Node* temp = head;

            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void split(Node* source, Node** frontRef, Node** backRef) {
            Node* slow = source;
            Node* fast = source->next;

            while (fast != nullptr) {
                fast = fast->next;
                if (fast != nullptr) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }

            *frontRef = source;
            *backRef = slow->next;
            slow->next = nullptr;
        }

        void split_v2(Node* source, Node* &frontRef, Node* &backRef) {
            Node* slow = source;
            Node* fast = source->next;

            while (fast != nullptr) {
                fast = fast->next;
                if (fast != nullptr) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }

            frontRef = source;
            backRef = slow->next;
            slow->next = nullptr;
        }

        Node* merging(Node* headRef) {
            if (headRef == nullptr || headRef ->next == nullptr) {
                return headRef;
            }

            Node* front = nullptr;
            Node* back = nullptr;
            split(headRef, &front, &back);

            front = merging(front);
            back = merging(back);

            return sortedMerge(front, back);
        }

        void mergeSort() {
            head = merging(head);
        }

        void insertionSort() {
            Node* sorted = nullptr;
            Node* current = head;

            while (current != nullptr) {
                Node* newNode = current->next;
                sorted = sortedInsertion(sorted, current);
                current = newNode;
            }
            head = sorted;
        }

        void copyToVector(vector<float> &vec) {
            Node* current = head;
            while (current != nullptr) {
                vec.push_back(current->data);
                current = current->next;
            }
        }
};

void displayArray(vector<float> vec) {
    for (float num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void bucketSort(vector<float> &vec) {
    vector<LinkedList> bucket(10);  // or LinkedList bucket(10);

    for (int i = 0; i < vec.size(); i++) {
        int index = vec[i] * 10;
        bucket[index].insert(vec[i]);
    }

    vec.clear();
    for (int i = 0; i < bucket.size(); i++) {
        bucket[i].insertionSort();

        // cout << "INDEX : "  << i << endl;
        // bucket[i].displayLinkedList();
        
        bucket[i].copyToVector(vec);
    }
}

void bucketSortWithMergeSort(vector<float> vec) {
    vector<LinkedList> bucket(10);

    for (float num : vec) {
        int index = 10 * num;
        bucket[index].insert(num);
    }

    cout << "Original Bucket : ";
    bucket[1].displayLinkedList();

    for (LinkedList &ls : bucket) {
        ls.mergeSort();
        ls.copyToVector(vec);
    }

    cout << "Sorted Bucket : ";
    bucket[1].displayLinkedList();
}

int main() {
    vector<float> vec = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68, 0.19};

    cout << "Original Array : " << endl;
    displayArray(vec);

    // bucketSort(vec);
    cout << endl << endl;
    bucketSortWithMergeSort(vec);
    cout << "Sorted Array : " << endl;
    displayArray(vec);

    // LinkedList ls;

    // ls.insert(0.3);
    // ls.insert(0.1);
    // ls.insert(0.23);

    // cout << endl;
    // cout << "Original LinkedList : " << endl;
    // ls.displayLinkedList();
    // cout << endl;

    // ls.insertionSort();
    // cout << "Sorted LinkedList : " << endl;
    // ls.displayLinkedList();
    
    return 0;
}