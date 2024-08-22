#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    int key;
    Node* prev;
    Node* next;

    Node(int key, int val) : data(val), key(key), prev(nullptr), next(nullptr) {};
};

class DoubleLinkedList {
    private :
        Node* head;
    
    public :
        DoubleLinkedList() : head(nullptr) {};

        void prepend(int key, int val) {

            Node* curr = searchKey(key);
            
            if (curr != nullptr) {
                curr->data = val;
            } else {
                Node* newNode = new Node(key, val);

                newNode->next = head;

                if (head != nullptr) {
                    head->prev = newNode;
                }

                head = newNode;
            }
        }

        Node* searchKey(int key) {
            Node* curr = head;

            while (curr != nullptr) {
                if (curr->key == key) {
                    return curr;
                }
                curr = curr->next;
            }

            return curr;
        }

        void deleteNode(int key) {
            Node* curr = searchKey(key);

            if (curr == nullptr) {
                cout << "No Delete Key" << endl;
                return;
            }

            Node* nextNode = curr->next;
            Node* prevNode = curr->prev;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        void displayList() {
            Node* curr = head;

            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;            
        }

        void displayPair() {
            Node* curr = head;

            while (curr != nullptr) {
                cout << "{" << curr->key << " : " << curr->data  << "} ";
                curr = curr->next;
            }
            cout << endl;      
        }
};

class ChainedHashTable {
    private :
        static const int MAX = 10;
        vector<DoubleLinkedList> vec;

    public :
        ChainedHashTable() : vec(MAX) {};

        int keyToIndex(int key) {
            return key % MAX;
        }

        void chainedHashInsert(int key, int val) {
            int Idx = keyToIndex(key);

            vec[Idx].prepend(key, val);
        }

        Node* chainedHashSearch(int key) {
            int Idx = keyToIndex(key);

            return vec[Idx].searchKey(key);
        }

        void chainedHashDelete(int key) {
            int Idx = keyToIndex(key);

            vec[Idx].deleteNode(key);
        }
        
        
        void displayHashTable() {
            for (int i = 0; i < MAX; i++) {
                cout << "key " << i << " : ";
                vec[i].displayList();
            }
        }

        void displayHashItems() {
            for (int i = 0; i < MAX; i++) {
                cout << "key " << i << " : ";
                vec[i].displayPair();
            }
        }
};

int main() {
    ChainedHashTable ht;

    ht.chainedHashInsert(1, 1);
    ht.chainedHashInsert(11, 2);
    ht.chainedHashInsert(21, 3);
    ht.chainedHashInsert(22, 4);
    ht.chainedHashInsert(23, 5);
    ht.chainedHashInsert(24, 6);
    ht.chainedHashInsert(35, 7);
    ht.chainedHashInsert(56, 8);
    ht.chainedHashInsert(67, 9);
    ht.chainedHashInsert(27, 10);
    ht.chainedHashInsert(27, 99);
    ht.chainedHashInsert(38, 12);
    ht.chainedHashInsert(49, 13);
    ht.chainedHashInsert(100, 14);
    ht.chainedHashInsert(0, 15);
    ht.chainedHashInsert(1, 20);

    ht.displayHashTable();

    ht.displayHashItems();
    return 0;
}