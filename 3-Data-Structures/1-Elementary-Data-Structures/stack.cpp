#include <bits/stdc++.h>

using namespace std;

class Stack {
    private :
        static const int MAX_SIZE = 10;
        int stk_arr[MAX_SIZE];
        int topIndex;

    public :
        Stack() : topIndex(-1) {}

        bool stackEmpty() {
            if (topIndex == -1) {
                return true;
            }

            return false;
        }

        void push(int val) {
            if (topIndex == MAX_SIZE) {
                throw overflow_error("Stack Overflow");
            } else {
                topIndex++;
                stk_arr[topIndex] = val;
            }
        }

        int pop() {
            if (stackEmpty()) {
                throw underflow_error("Stack Underflow");
                
                return -1;
            } else {
                int res = stk_arr[topIndex];
                topIndex--;

                return res;
            }
        }

        void displayStack() {
            for (int i = 0; i <= topIndex; i++) {
                cout << stk_arr[i] << " ";
            }
            cout << endl << endl;
        }
};

class StackVector {
    private :
        vector<int> stk_vec;

    public :
        StackVector() {}

        void push(int val) {
            stk_vec.push_back(val);
        }

        int pop() {
            if (stk_vec.empty()) {
                throw underflow_error("Stack Underflow");
                return -1;
            } else {
                int res = stk_vec.back();
                stk_vec.pop_back();

                return res;
            }
        }

        void displayStack() {
            for (int num : stk_vec) {
                cout << num << " ";
            }
            cout << endl << endl;
        }
};

class Node {
    public :
        int val;
        Node* next;

        Node(int value) : val(value), next(nullptr) {};
};

class StackLinkedList {
    private :
        Node* head;

    public :
        StackLinkedList() : head(nullptr) {};

        bool stackEmpty() {
            return head == nullptr;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        int pop() {
            if (stackEmpty()) {
                throw underflow_error("Stack Underflow");
                return -1;
            } else {
                int res = head->val;
                head = head->next;

                return res;
            }
        }

        void displayStack() {
            vector<int> elements;
            Node* current = head;

            while (current != nullptr) {
                elements.push_back(current->val);
                current = current->next;
            }

            for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
                cout << *it << " ";
            }
            cout << endl << endl;
        }
        
};

int main() {
    srand(time(0));
    
    Stack stk_arr;

    for (int i = 0; i < 8; i++) {
        stk_arr.push(rand() % 21);
    }

    cout << "Stack with Array Implementation : " << endl;
    stk_arr.displayStack();

    int arr_pop = stk_arr.pop();
    cout << "Last Value = " << arr_pop << endl;
    cout << "New Stack : " << endl;
    stk_arr.displayStack();

    StackVector stk_vec;

    for (int i = 0; i < 8; i++) {
        stk_vec.push(rand() % 20);
    }

    cout << "Stack with Vector Implementation : " << endl;
    stk_vec.displayStack();

    int vec_pop = stk_vec.pop();
    cout << "Last Value = " << vec_pop << endl;
    cout << "New Stack : " << endl;
    stk_vec.displayStack();

    StackLinkedList stk_ls;

    for (int i = 0; i < 8; i++) {
        stk_ls.push(rand() % 20);
    }

    cout << "Stack with LinkedList Implementation : " << endl;
    stk_ls.displayStack();

    int ls_pop = stk_ls.pop();
    cout << "Last Value = " << ls_pop << endl;
    cout << "New Stack : " << endl;
    stk_ls.displayStack();
    
}