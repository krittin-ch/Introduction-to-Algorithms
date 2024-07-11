#include <bits/stdc++.h>

using namespace std;

int NaivePolynomial(int A[], int n, int x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a = A[i];
        for (int j = 1; j < n; j++) {
            a *= x;
        }
        sum += a;
    }

    return sum;
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    int sum = NaivePolynomial(arr, 8, 2);

    cout << "Total NaivePolynomial : " << sum;

    return 0;
}