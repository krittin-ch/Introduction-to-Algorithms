#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void medianOfThree(vector<int> &vec, int p, int r) {
    if (p - r + 1 < 3 || p >= r) {
        return;
    }

    int m = (p + r) / 2;
    int left = vec[p];
    int mid = vec[m];
    int right = vec[r];
    int pivotIdx = (left > right) ? ((mid > right) ? mid : right) : ((mid > left) ? mid : left);

    swap(vec[r], vec[pivotIdx]);
}

int medianOfThreePartition(vector<int> &vec, int p, int r) {
    
    medianOfThree(vec, p, r);
    
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

void quicksort(vector<int> &vec, int p, int r) {
    if (p >= r) {
        return;
    }
    
    int q = medianOfThreePartition(vec, p, r);

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