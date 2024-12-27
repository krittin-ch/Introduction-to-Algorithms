#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* np;   // next XOR prev

    Node(int val) {
        data = val;
        np = nullptr;
    }
};

struct SearchResult {
    Node* curr;
    Node* prev;
};

class DoublyLinkedListWithXOR {
    private:
        Node* head;

        Node* XOR(Node* a, Node* b) {
            return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
        }

    public:
        DoublyLinkedListWithXOR() : head(nullptr) {};

        Node* getNext(Node* prev, Node* curr) {
            return XOR(prev, curr->np);
        }

        void prepend(int val) {
            Node* newNode = new Node(val);

            if (head == nullptr) {
                head = newNode;
            } else {
                newNode->np = XOR(nullptr, head);
                head->np = XOR(newNode, XOR(nullptr, head->np));
                head = newNode;
            }
        }

        SearchResult search(int val) {
            Node* curr = head;
            Node* prev = nullptr;
            Node* next;

            while (curr != nullptr) {
                if (curr->data == val) {
                    return {curr, prev};
                }
                next = getNext(prev, curr);
                prev = curr;
                curr = next;
            }

            return {curr, prev}; // Node not found
        }

        void insert(int insertVal, int searchVal) {
            SearchResult res = search(searchVal);
            if (res.curr == nullptr) {
                prepend(insertVal); // If the search fails, prepend the value
                return;
            }

            Node* newNode = new Node(insertVal);
            Node* curr = res.curr;
            Node* prev = res.prev;
            Node* next = getNext(prev, curr); // Determine the next node from the current

            newNode->np = XOR(curr, next); // The new node's np is XOR of curr and next
            curr->np = XOR(prev, newNode); // Update current node's np to include the new node

            if (next != nullptr) {
                next->np = XOR(newNode, XOR(curr, next->np)); // Update next node's np to include the new node
            }
        }

        void remove(int val) {
            Node* curr = head;
            Node* prev = nullptr;
            Node* next = nullptr;

            while (curr != nullptr) {
                next = getNext(prev, curr);

                if (curr->data == val) {
                    if (prev != nullptr) {
                        prev->np = XOR(XOR(prev->np, curr), next);
                    } else {
                        head = next;  // Update head if head is being removed
                    }

                    if (next != nullptr) {
                        next->np = XOR(prev, XOR(curr, next->np));
                    }

                    delete curr;
                    return;
                }
                prev = curr;
                curr = next;
            }
        }

        void displayLinkedList() {
            Node* curr = head;
            Node* prev = nullptr;
            Node* next;

            while (curr != nullptr) {
                cout << curr->data << " ";
                next = getNext(prev, curr);
                prev = curr;
                curr = next;
            }
            cout << endl;
        }
};

int main() {
    DoublyLinkedListWithXOR ls;

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

    cout << "Linked List After Delete : " << endl;
    ls.displayLinkedList();

    return 0;
}
