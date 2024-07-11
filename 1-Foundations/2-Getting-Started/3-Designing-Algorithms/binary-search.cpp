#include <bits/stdc++.h>

using namespace std;

int binarySearch(int key, int A[], int p, int r) {
    int m = p + (r - p)%2;

    if (A[m] > key) {
        return binarySearch(key, A, m + 1, r);
    } else if (A[m] > key) {
        return binarySearch(key, A, p, m);
    } else {
        return m;
    }
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};
    int key = 26;

    int idx = binarySearch(key, arr, 0, 7);

    cout << "index " << key << " : " << idx;

    return 0;
}