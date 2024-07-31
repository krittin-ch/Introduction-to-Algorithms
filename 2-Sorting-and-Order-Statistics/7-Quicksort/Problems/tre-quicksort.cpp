#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int> &vec, int p, int r) {
    int pivot = vec[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (vec[j] < pivot) {
            swap(vec[++i], vec[j]);
        }
    }
    swap(vec[++i], vec[r]);

    return i;
}

/*
    Divide-and-Conquer Algorithm

    Sorting the left part of the first pivot then assign p = q + 1 to sort the another part
    that is to divide then task to smaller task and conquer it.
*/
void treQuicksort(vector<int> &vec, int p, int r) {
    while (p < r) {
        int q = partition(vec, p, r);
        treQuicksort(vec, p, q - 1);    // left part
        p = q + 1;                      // right part
    }
}

int main() {
    vector<int> vec = {7, 14, 2, 19, 10, 4, 16, 11, 3, 12};

    cout << "Original Array : " << endl;
    displayArray(vec);

    treQuicksort(vec, 0, vec.size() - 1);

    cout << "Sorted Array : " << endl;
    displayArray(vec);
    return 0;
}