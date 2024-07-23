#include <bits/stdc++.h>

using namespace std;

void randomSample(int S[], int m, int n) {
    unordered_set<int> used;
    for (int a = 0; a < m; a++) {
        int k = a + n - m;
        int i = rand() % k;
        if (used.find(i) != used.end()) {
            S[a] = k;
        } else {
            S[a] = i;
        }
        used.insert(S[a]);
    }
}

void displayArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int n = 10;
    int m = 8;
    int S[m];

    randomSample(S, m, n);

    cout << "Display Array" << endl;
    displayArray(S, m);

    return 0;
}