#include <bits/stdc++.h>

using namespace std;

// This implementation is required for bucket sort
class Node {
    private:
        int data;
        Node* next;

    public:
        Node(int val) : data(val), next(nullptr) {}
        
        int getData() const { return data; }
        
        void setData(int val) { data = val; }
        
        Node* getNext() const { return next; }
        
        void setNext(Node* nextNode) { next = nextNode; }
};

/*
OR

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
*/

class LinkedList {
    private:
        Node* head;

        Node* sortedInsert(Node* headRef, Node* newNode) {
            if (headRef == nullptr || headRef->getData() >= newNode->getData()) {
                newNode->setNext(headRef);
                return newNode;
            }

            Node* current = headRef;
            
            while (current->getNext() != nullptr && current->getNext()->getData() < newNode->getData()) {
                current = current->getNext();
            }

            newNode->setNext(current->getNext());
            current->setNext(newNode);

            return headRef;
        }

    public:
        LinkedList() : head(nullptr) {}

        void insert(int val) {
            Node* newNode = new Node(val);
            newNode->setNext(head); // newNode->next = head; can also be applied if "next" is set to public not private.
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

        void insertionSort() {
            Node* sorted = nullptr;
            Node *current = head;

            while (current != nullptr) {
                Node* newNode = current->getNext();
                sorted = sortedInsert(sorted, current);
                current = newNode;
            }

            head = sorted;
        }
};

int main() {

    LinkedList list;

    list.insert(2);
    list.insert(4);
    list.insert(3);
    list.insert(1);
    list.insert(10);

    cout << "Display Linked List : " << endl;
    list.displayLinkedList();

    cout << "Sorted Linked List : " << endl;
    list.insertionSort();
    list.displayLinkedList();


    return 0;
}