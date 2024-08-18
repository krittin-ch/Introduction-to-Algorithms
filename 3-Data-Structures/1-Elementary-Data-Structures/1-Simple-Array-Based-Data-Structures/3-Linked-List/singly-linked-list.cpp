#include <bits/stdc++.h>

using namespace std;

class Node {
    private :
        int data;
        Node* next;

    public :
        Node(int val) : data(val), next(nullptr) {};

        int getData() const {
            return data;
        }

        Node* getNext() const {
            return next;
        }

        void setData(int val) {
            data = val;
        } 

        void setNext(Node* nextNode) {
            next = nextNode;
        }
};

struct SearchResult {
    Node* curr;
    Node* prev;
};

class SinglyLinkedList {
    private :
        Node* head;

        bool contains(int val) const {
            Node* curr = head;
            while (curr != nullptr) {
                if (curr->getData() == val) {
                    return true;
                }
                curr = curr->getNext();
            }
            return false;
        }

    public :
        SinglyLinkedList() : head(nullptr) {};

        void prepend(int val) {
            Node* newNode = new Node(val);
            newNode->setNext(head);
            head = newNode;
        }

        SearchResult search(int val) {
            Node* curr = head;
            Node* prev = nullptr;

            while (curr != nullptr && curr->getData() != val) {
                prev = curr;
                curr = curr->getNext();
            }

            return {curr, prev};
        }

        void insert(int insertVal, int searchVal) {
            SearchResult res = search(searchVal);

            Node* curr = res.curr;

            // not find the search key
            if (curr == nullptr) {
                prepend(insertVal);
                return;
            }

            Node* newNode = new Node(insertVal);
            Node* prev = res.prev;
            // insert at the front of the search key
            newNode->setNext(curr);
            prev->setNext(newNode);
        }

        void remove(int val) {
            SearchResult res = search(val);
            
            Node* curr = res.curr;

            if (curr == nullptr) {
                cout << "Delete Key Not Found" << endl;
                return;
            }

            Node* prev = res.prev;
            prev->setNext(curr->getNext());
        }

        void displayLinkedList() {
            Node* curr = head;

            while (curr != nullptr) {
                cout << curr->getData() << " ";
                curr = curr->getNext();
            }
            cout << endl;
        }
        
        void unionWith(const SinglyLinkedList &ls) {
            Node* curr = ls.head;

            while (curr != nullptr) {
                if (!contains(curr->getData())) {
                    prepend(curr->getData());
                }
                curr = curr->getNext();
            }
        }

        void naiveUnionWith(const SinglyLinkedList &ls) {
            Node* curr = ls.head;

            while (curr != nullptr) {
                prepend(curr->getData());
                curr = curr->getNext();
            }
        }
};

int main() {
    SinglyLinkedList ls_1;

    ls_1.prepend(2);
    ls_1.prepend(12);
    ls_1.prepend(4);
    ls_1.prepend(3);
    ls_1.prepend(6);
    ls_1.prepend(9);

    cout << "Original Linked List : " << endl;
    ls_1.displayLinkedList();

    ls_1.insert(99, 12);
    ls_1.insert(11, 99);
    ls_1.insert(1, 5);

    cout << "Linked List After Insert : " << endl;
    ls_1.displayLinkedList();

    ls_1.remove(4);
    ls_1.remove(3);
    // ls_1.remove(100);

    cout << "Linked List After Delete : " << endl;
    ls_1.displayLinkedList();

    SinglyLinkedList ls_2;

    for (int i = -5; i < 3; i++) {
        ls_2.prepend(i);
    }

    cout << "Linked List 2 : " << endl;
    ls_2.displayLinkedList();


    cout << "Linked List 1 After Union : " << endl;
    // ls_1.naiveUnionWith(ls_2);
    ls_1.unionWith(ls_2);
    ls_1.displayLinkedList();

    return 0;
}
