#include <bits/stdc++.h>

using namespace std;

class QueueWith2Stacks {
    private :
        stack<int> stk_in;
        stack<int> stk_out;

        void reverseQueue() {
            while (!stk_out.empty()) {
                stk_in.push(stk_out.top());
                stk_out.pop();
            }
        }

        void forwardQueue() {
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }

    public :
        QueueWith2Stacks() {}

        void enqueue(int val) {
            reverseQueue();
            stk_in.push(val);
            forwardQueue();
        }

        int dequeue() {
            int val = stk_out.top();
            stk_out.pop();

            return val;
        }

        void displayQueue() {
            stack<int> stk_temp = stk_out;

            while (!stk_temp.empty()) {
                cout << stk_temp.top() << " ";
                stk_temp.pop();
            }
            cout << endl;
        } 
};

int main() {

    QueueWith2Stacks queue;

    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(12);

    cout << "Original Queue : " << endl;
    queue.displayQueue();

    cout << "Queue After Dequeue : " << endl;
    queue.dequeue();
    queue.displayQueue();

    return 0;
}