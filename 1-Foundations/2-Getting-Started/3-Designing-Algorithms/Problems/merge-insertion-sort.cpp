#include <bits/stdc++.h>

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

void insertionSort(int A[], int p, int r) {
    for (int i = p + 1; i < r + 1; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= p && key < A[j]) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

void merge(int A[], int p, int m, int r) {
    int nL = m - p + 1;
    int nR = r - m;
    
    int L[nL];
    int R[nR];
    
    for (int i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < nR; j++) {
        R[j] = A[(m + 1) + j];
    }

    int i = 0, j = 0, k = p;

    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }    
}

void mergeInsertionSort(int A[], int p, int r) {
    int maxSubArrSize = 3;
    if (p + (maxSubArrSize - 1) >= r) {
        insertionSort(A, p, r);
        return;
    }

    int m = p + (r - p)/2;

    mergeInsertionSort(A, p, m);
    mergeInsertionSort(A, m + 1, r);
    merge(A, p, m, r);
}


int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    mergeInsertionSort(arr, 0, 7);
    display_array(arr, 8);
    
    return 0;
}