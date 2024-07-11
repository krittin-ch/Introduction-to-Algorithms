#include <bits/stdc++.h>

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

void insert(int A[], int n) {
    int key = A[n];
    int j = n - 1;

    while (j >= 0 && key < A[j]) {
        A[j + 1] = A[j];
        j--;
    }

    A[j + 1] = key;
}

void insertionSortRecurvise(int A[], int n) {
    if (n <= 1) {
        return;
    }

    n--;
    insertionSortRecurvise(A, n);
    insert(A, n);
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    insertionSortRecurvise(arr, 8);

    display_array(arr, 8);

    return 0;
}