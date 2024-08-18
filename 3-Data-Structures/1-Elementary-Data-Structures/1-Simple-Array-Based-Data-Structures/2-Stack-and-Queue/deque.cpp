#include <bits/stdc++.h>

using namespace std;

class Deque {
    private :
        stack<int> stk;
        queue<int> que;

    public :
        Deque() {};

        void push_front(int val) {
            stk.push(val);
        }

        void push_back(int val) {
            que.push(val);
        }

        int pop_front() {
            if (stk.empty()) {
                if (que.empty()) {
                    cout << "Deque is Underflow";
                    return -1;
                }

                while (!que.empty()) {
                    stk.push(que.front());
                    que.pop();
                }
            }

            int temp = stk.top();
            stk.pop();

            return temp;
        }

        int pop_back() {
            if (que.empty()) {
                if (stk.empty()) {
                    cout << "Deque is Underflow";
                    return -1;
                }

                while (!stk.empty()) {
                    que.push(stk.top());
                    que.pop();
                }
            }

            int temp = que.back();

            queue<int> tempQueue;

            while (que.size() > 1) {
                tempQueue.push(que.front());
                que.pop();
            }

            que.pop();

            que = tempQueue;

            return temp;

        }

        void displayDeque() {
            stack<int> tempStack = stk;
            queue<int> tempQueue = que;

            // Display elements in the stack (front of deque)
            cout << "Deque elements (front to back): ";
            vector<int> stackElements;

            while (!tempStack.empty()) {
                stackElements.push_back(tempStack.top());
                tempStack.pop();
            }

            // Stack elements are displayed in reverse order (from bottom to top)
            for (int i = stackElements.size() - 1; i >= 0; i--) {
                cout << stackElements[i] << " ";
            }

            // Display elements in the queue (back of deque)
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }

            cout << endl;
        }

};

int main() {
    Deque dq;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_back(4);

    cout << "Original Deque : " << endl;
    dq.displayDeque();


    cout << "Pop front: " << dq.pop_front() << endl;  // 3
    cout << "Pop back: " << dq.pop_back() << endl;    // 4

    cout << "Deque After Pop :" << endl;
    dq.displayDeque();
    
    return 0;
}
