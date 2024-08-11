#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &vec, int start, int step, int length) {
    for (int i = 1; i < length; i++) {
        int key = vec[start + step * i];
        int j = i - 1;

        while (j >= 0 && vec[start + step * j] > key) {
            vec[start + step * (j + 1)] = vec[start + step * j];
            j--;
        }
        vec[start + step * (j + 1)] = key;
    }
}

int partitionAround(vector<int> &vec, int p, int r, int x) {
    int idx = p;
    while (vec[idx] != x && idx <= r) {
        idx++;
    }

    swap(vec[idx], vec[r]);

    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (vec[j] < x) {
            swap(vec[++i], vec[j]);
        }
    }

    swap(vec[++i], vec[r]);

    return i;
}

int select(vector<int> &vec, int p, int r, int i) {
    if (p == r) {
        return vec[p];
    }

    int n = r - p + 1;
    int g = (n + 4) / 5;
    vector<int> medians(g);

    for (int j = 0; j < g; j++) {
        int start = p + j * 5;
        int length = min(5, n - j * 5);
        insertionSort(vec, start, 1, length);
        medians[j] = vec[start + length / 2];
    }

    // medOfMed is a median of each 5-element group of A[j + p] for j = p to p + g
    // which are vec[p + 2*g], vec[p + 1 + 2*g], ..., vec[p + (g - 1) + 2*g]
    int medOfMed = (g == 1) ? medians[0] : select(medians, 0, g - 1, g / 2);

    int q = partitionAround(vec, p, r, medOfMed);
    int k = q - p + 1;

    if (i == k) {
        return vec[q];
    } else if (i < k) {
        return select(vec, p, q - 1, i);
    } else {
        return select(vec, q + 1, r, i - k);
    }
}

void quicksort(vector<int> &vec, int p, int r) {
    if (p > r) {
        return;
    }
    int mid = (p - r) / 2;
    
    int pivot = select(vec, p, r, mid);
    int q = partitionAround(vec, p, r, pivot);

    quicksort(vec, p, q - 1);
    quicksort(vec, q + 1, r);
}

int main() {
    vector<int> vec = {4, 3, 2, 6, 1, 5, 10, 8, 7, 9};
    
    cout << "Original Array : " << endl;
    displayArray(vec);

    cout << "Sorted Array : " << endl;
    quicksort(vec, 0, vec.size() - 1);
    displayArray(vec);
    
    return 0;
}
