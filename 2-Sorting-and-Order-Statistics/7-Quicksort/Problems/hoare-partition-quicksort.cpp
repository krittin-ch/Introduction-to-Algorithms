#include <bits/stdc++.h>

using namespace std;

/*
    do-while Loop: Guarantees execution of the loop body at least once.

    do {
        // Loop body
    } while (condition);

    while Loop: Executes the loop body based on the condition, which can be false from the start.

    while (condition) {
        // Loop body
    }
*/ 

void displayPartition(vector<int> vec, int p, int r) {
    for (int i = p; i <= r; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int hoarePartition(vector<int> &vec, int p, int r) {
    int pivot = vec[p];

    int i = p - 1;
    int j = r + 1;
    while (true) {

        // "j" is the correct index of "x"
        // other elements are swapped between "x" until the array settle
        do {
            j--;
        } while (vec[j] > pivot);

        do {
            i++;
        } while (vec[i] < pivot);

        if (i < j) {
            swap(vec[i], vec[j]);
        } else {
            return j;
        }
    }
}

void quicksort(vector<int> &vec, int p, int r) {
    if (p >= r) {
        return;
    }

    int x = vec[p];
    int q = hoarePartition(vec, p, r);
    int i = 0;

    do {
        i++;
    } while (vec[i] != x);
    
    if (i <= q) {
        /*
            swap index "i" and "q"
            Start : 3 4(pivot = i) 1 2(q) 5 9 8 7
            Finish : 3 1 2 4(pivot) 9 8 5 7
        */
        swap(vec[i], vec[q]);
    } else {
        /*
            swap index "i" and "q + 1"

            Start : 3 1 2(q) 5(q + 1) 9 8 4(pivot = i) 7
            Finish : 3 1 2 4(pivot) 9 8 5 7
        */
        swap(vec[i], vec[++q]);
    }
    
    quicksort(vec, p, q - 1);
    quicksort(vec, q + 1, r);
}

int main() {
    vector<int> vec = {7, 14, 2, 19, 10, 4, 16, 11, 3, 12};

    cout << "Original Array : " << endl;
    displayArray(vec);

    quicksort(vec, 0, vec.size() - 1);    
    cout << "Sorted Array : " << endl;
    displayArray(vec);

    return 0;
}