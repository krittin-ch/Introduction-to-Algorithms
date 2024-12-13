#include <bits/stdc++.h>

using namespace std;

class Queue {
    private:
        static const int MAX_SIZE = 10;
        int queue[MAX_SIZE];
        
        int headIdx;
        int tailIdx;
    
    public:
        Queue() : headIdx(0), tailIdx(-1) {};

        int incrementIdx(int Idx) {
            return (Idx + 1) % MAX_SIZE;
        }

        int decrementIdx(int Idx) {
            Idx--;

            return Idx > 0 ? Idx : MAX_SIZE - 1;
        }

        bool queueEmpty() {
            if (tailIdx == -1) {
                return true;
            }

            return headIdx == incrementIdx(tailIdx + 1);
        }

        bool queueFull() {
            if (tailIdx == -1) {
                return false;
            }

            return incrementIdx(tailIdx) == headIdx;
        }

        void enqueue(int val) {
            if (queueFull()) {
                cout << "The Queue is full" << endl;
                throw overflow_error("Queue Overflow");
            }

            tailIdx = incrementIdx(tailIdx);
            queue[tailIdx] = val; 
        }

        void dequeue() {
            if (queueEmpty()) {
                cout << "The Queue is empty" << endl;
                throw underflow_error("Queue Underflow");
            }
            headIdx = incrementIdx(headIdx);
        }

        void displayQueue() {
            if (headIdx <= tailIdx) {

                for (int i = 0; i < headIdx; i++) {
                    cout << "X" << " ";
                }

                for (int i = headIdx; i < tailIdx; i++) {
                    cout << queue[i] << " ";
                }

                for (int i = tailIdx; i < MAX_SIZE; i++) {
                    cout << "X" << " ";
                }

            } else {
                for (int i = 0; i < tailIdx; i++) {
                    cout << queue[i] << " ";
                }

                for (int i = tailIdx; i < headIdx; i++) {
                    cout << "X" << " ";
                }

                for (int i = headIdx; i < MAX_SIZE; i++) {
                    cout << queue[i] << " ";
                }
            }

            cout << endl << endl;
        }
};
int main() {
    srand(time(0));

    Queue queue;

    for (int i = 0; i < 8; i++) {
        queue.enqueue(rand() % 20);
    }

    cout << "Queue Original State : " << endl;
    queue.displayQueue();

    for (int i = 0; i < 3; i++) {
        queue.dequeue();
    }

    cout << "Queue State After Dequeue : " << endl;
    queue.displayQueue();

    for (int i = 0; i < 10; i++) {
        queue.enqueue(rand() % 20);
    }

    cout << "Queue State After Enqueue : " << endl;
    queue.displayQueue();
    
    return 0;
}