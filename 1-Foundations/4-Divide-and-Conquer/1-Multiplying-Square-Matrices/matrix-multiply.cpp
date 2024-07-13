#include <bits/stdc++.h>

// Intuitive Matrix Multiplication
// Time Complexity : O(n^3)

using namespace std;

void matrixMultiply(int A[][100], int B[][100], int C[][100], int m, int n, int p) {
    // A[m][n] times B[n][p] results in C[m][p]
    // C[100][100] is initialized by zeros

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void initizializeZeros(int C[][100], int m, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }
}

void displayMatrix(int M[][100], int n, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            // cout << "Value at (" << i << "," << j << ") : " << M[i][j]; 
            cout << M[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int m = 7;
    int n = 7;
    int p = 7;

    int A[100][100], B[100][100], C[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (i + 1)*(j - 1);
        }
    }

    cout << "Matrix A :\n";
    displayMatrix(A, m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = 2*i + (j + 1);
        }
    }

    cout << "Matrix B :\n";
    displayMatrix(B, n, p);

    initizializeZeros(C, m, p);

    // C = A*B
    matrixMultiply(A, B, C, m, n, p);

    cout << "Product Matrix C :\n";
    displayMatrix(C, m, p);

    return 0;

}