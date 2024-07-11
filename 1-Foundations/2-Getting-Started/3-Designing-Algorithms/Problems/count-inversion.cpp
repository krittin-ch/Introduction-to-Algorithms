#include <bits/stdc++.h>

using namespace std;

int mergeCountInversion (int A[], int p, int m, int r) {
    int nL = m - p + 1;
    int nR = r - m;
    int L[nL];
    int R[nR];
    int count = 0;

    for (int i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < nR; j++) {
        R[j] = A[(m + 1) + j];
    }

    int i = 0, j = 0, k = p;

    while (i < nL && j < nR) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            count += (nL - i);
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

    return count;
}

int mergeSortCountInversion(int A[], int p, int r) {
    int count = 0;

    if (p >= r) {
        return 0;
    }

    int m = (p + r)/2;
    count += mergeSortCountInversion(A, p, m);
    count += mergeSortCountInversion(A, m + 1, r);
    count += mergeCountInversion(A, p, m, r);

    return count;
}

int main() {
    int arr[5] = {2, 3, 8, 6, 1};

    int countInversion = mergeSortCountInversion(arr, 0, 4);

    cout << "Inversion Count : " << countInversion;
}