#include <bits/stdc++.h>

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            if (A[j] < A[j-1]) {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    bubbleSort(arr, 8);

    display_array(arr, 8);
    return 0;
}