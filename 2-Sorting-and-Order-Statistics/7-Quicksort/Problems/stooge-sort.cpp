#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void stoogeSort(vector<int> &vec, int p, int r) {
    if (vec[p] > vec[r]) {
        swap(vec[p], vec[r]);
    }
    
    if (p + 1 < r) {
        int k = (r - p + 1) / 3;    // round down
        stoogeSort(vec, p, r - k);  // first two-thirds
        stoogeSort(vec, p + k, r);  // last two-thirds
        stoogeSort(vec, p, r - k);  // first two-thirds again
    }
}

int main() {
    vector<int> vec = {7, 14, 2, 19, 10, 4, 16, 11, 3, 12};

    cout << "Original Array : " << endl;
    displayArray(vec);

    stoogeSort(vec, 0, vec.size() - 1);

    cout << "Sorted Array : " << endl;
    displayArray(vec);
    return 0;
}