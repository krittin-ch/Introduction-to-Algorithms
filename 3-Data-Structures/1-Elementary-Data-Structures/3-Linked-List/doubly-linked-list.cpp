#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {};
};

class DoublyLinkedList {
    private :
        Node* head;

    public :
        DoublyLinkedList() : head(nullptr) {};

        void prepend(int val) {
            Node* newNode = new Node(val);
            if (head != nullptr) {
                newNode->next = head;
                head->prev = newNode;
            }
            head = newNode;
        }


        Node* search(int val) {
            Node* curr = head;

            while (curr != nullptr && curr->data != val) {
                curr = curr->next;
            }

            return curr;
        }

        void insert(int insertVal, int searchVal) {
            Node* curr = search(searchVal);
            
            
            if (curr == nullptr) {
                prepend(insertVal);
                return;
            }

            Node* newNode = new Node(insertVal);
            Node* prev = curr->prev;

            newNode->next = curr;
            curr->prev = newNode;

            prev->next = newNode;
            newNode->prev = prev;
        }

        void remove(int val) {
            Node* curr = search(val);

            if (curr == nullptr) {
                cout << "Delete Key Not Found" << endl;
                return;
            }

            Node* prev = curr->prev;

            prev->next = curr->next;
            curr->next->prev = prev;
        }

        void displayLinkedList() {
            Node* curr = head;

            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }

};

int main() {
    DoublyLinkedList ls;
    
    ls.prepend(2);
    ls.prepend(12);
    ls.prepend(4);
    ls.prepend(3);
    ls.prepend(6);
    ls.prepend(9);

    cout << "Original Linked List : " << endl;
    ls.displayLinkedList();

    ls.insert(99, 12);
    ls.insert(11, 99);
    ls.insert(1, 5);

    cout << "Linked List After Insert : " << endl;
    ls.displayLinkedList();

    ls.remove(4);
    ls.remove(3);
    // ls.remove(100);

    cout << "Linked List After Delete : " << endl;
    ls.displayLinkedList();

    return 0;
}