#include <bits/stdc++.h>

// Selection Sort : Select and swap the minimum value from the unsorted array to the first index of the iteration
int minimumIndex(int A[], int s, int e) {
    int min = s;
    for (int i = s; i < e; i++) {
        if (A[min] > A[i]) {
            min = i;
        }
    }

    return min;
}

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = minimumIndex(A, i, n);
        
        int temp = A[minIndex];
        A[minIndex] = A[i];
        A[i] = temp;
    }
}


void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[6] = {31, 41, 59, 26, 41, 58};

    selectionSort(arr, 6);

    display_array(arr, 6);

    return 0;
}