#include <iostream>

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

// merge subarrays into the main array
void merge(int A[], int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;

    int L[nL];
    int R[nR];

    for (int i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < nR; j++) {
        R[j] = A[(q + 1) + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < nL && j < nR) {
        if (L[i] < R[j]) {
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
        k++;
        i++;
    }

    while (j < nR) {
        A[k] = R[j];
        k++;
        j++;
    }
}

// p is the beginning index of the (sub)array
// r is the ending index of the (sub)array
void mergeSort(int A[], int p, int r) {
    if (p >= r) {
        // avoid p being greater than r
        // making the merge function be called in the previous stage (before p = r) with the subarray size of 3
        return;
    }
    
    int q = p + (r - p)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A, p, q, r);
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    mergeSort(arr, 0, 7);
    display_array(arr, 8);
    
    return 0;
}