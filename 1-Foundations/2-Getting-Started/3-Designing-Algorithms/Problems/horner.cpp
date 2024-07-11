#include <bits/stdc++.h>

using namespace std;

int hornerRule(int A[], int n, int x) {
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum = sum*x + A[i]; 
    }

    return sum;
}

int main() {
    int arr[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    int sum = hornerRule(arr, 8, 2);

    cout << "Total Horner's Summation : " << sum;

    return 0;
}