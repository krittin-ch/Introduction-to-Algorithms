#include <bits/stdc++.h>

using namespace std;

class Stackwith2Queues {
    private :
        queue<int> queue_1;
        queue<int> queue_2;

    public :
        Stackwith2Queues() {}

        void push(int val) {
            queue_1.push(val);
        }

        int pop() {

            if (queue_1.empty()) {
                cout << "The Queue is Underflow" << endl;
                return -1;
            }

            while (queue_1.size() > 1) {
                queue_2.push(queue_1.front());
                queue_1.pop();
            }

            int temp = queue_1.front();
            queue_1.pop();

            swap(queue_1, queue_2);

            return temp;
        }

        void displayStack() {
            queue<int> temp = queue_1;

            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }

            cout << endl;
        }
};

int main() {
    Stackwith2Queues stk;

    stk.push(1);
    stk.push(3);
    stk.push(4);
    stk.push(6);

    cout << "Original Stack : " << endl;
    stk.displayStack();

    cout << "Stack After Pop : " << endl;
    stk.pop();
    stk.displayStack();

    return 0;
}