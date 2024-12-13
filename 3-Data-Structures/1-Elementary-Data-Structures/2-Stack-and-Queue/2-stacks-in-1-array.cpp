#include <bits/stdc++.h>

using namespace std;

class Stack_2In1 {
    private:
        static const int MAX_SIZE = 20;
        int arr[MAX_SIZE];
        
        int stk_1_top = -1;
        int stk_1_bottom = 0;

        int stk_2_top = MAX_SIZE;
        int stk_2_bottom = MAX_SIZE - 1;

    public:
        Stack_2In1() {};

        bool isFull() {
            return stk_1_top == stk_2_top;
        }

        bool isStack1Empty() {
            return stk_1_top == -1;
        }

        bool isStack2Empty() {
            return stk_2_top == MAX_SIZE;
        }

        void pushStack1(int val) {
            if (isFull()) {
                cout << "The Array Overflow" << endl;
                return;
            }

            arr[++stk_1_top] = val;
        }

        void pushStack2(int val) {
            if (isFull()) {
                cout << "The Array Overflow" << endl;
                return;
            }

            arr[--stk_2_top] = val;
        }

        int popStack1() {
            if (isStack1Empty()) {
                cout << "Stack 1 Underflow" << endl;
                return -1;
            }

            int val = arr[stk_1_top--];
            
            return val;
        }
        int popStack2() {
            if (isStack2Empty()) {
                cout << "Stack 2 Underflow" << endl;
                return -1;
            }

            int val = arr[stk_2_top++];
            
            return val;
        }
        
        void displayArray() {
            for (int i = stk_1_bottom; i <= stk_1_top; i++) {
                cout << arr[i] << " ";
            }

            for (int i = stk_1_top + 1; i < stk_2_top; i++) {
                cout << "X ";
            }

            for (int i = stk_2_top; i <= stk_2_bottom; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void displayStack1() {
            cout << "Bottom ";
            for (int i = stk_1_bottom; i <= stk_1_top; i++) {
                cout << arr[i] << " ";
            }
            cout << "Top";
            cout << endl;
        }

        void displayStack2() {
            cout << "Bottom ";
            for (int i = stk_2_bottom; i >= stk_2_top; i--) {
                cout << arr[i] << " ";
            }
            cout << "Top";
            cout << endl;
        }
        
        void displayStack() {
            cout << "Stack 1 : ";
            displayStack1();

            cout << endl;
            cout << "Stack 2 : ";
            displayStack2();
        }
};

int main() {
    srand(time(0));

    Stack_2In1 stk;

    for (int i = 0; i < 8; i++) {
        stk.pushStack1(i);
        stk.pushStack2(i);
    }

    stk.displayArray();

    int popVal1 = stk.popStack1();
    stk.displayArray();

    int popVal2 = stk.popStack2();
    stk.displayArray();

    cout << "Popped Val 1 : " << popVal1 << endl;
    cout << "Popped Val 2 : " << popVal2 << endl;

    for (int i = 0; i < 2; i++) {
        stk.pushStack1(i);
        stk.pushStack2(i);
    }

    stk.displayArray();
    cout << endl;

    stk.displayStack1();
    stk.displayStack2();

    for (int i = 0; i < 5; i++) {
        // Overflow Test
        stk.pushStack1(i);
        stk.pushStack2(i);
    }

    stk.displayStack();

    for (int i = 0; i < 14; i++) {
        // Underflow Test
        stk.popStack1();
        stk.popStack2();
    }

    stk.displayArray();

    return 0;
}