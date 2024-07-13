#include <bits/stdc++.h>

// Simple Matrix Recursive Multiplication (square matrix dimension is an exact power of 2: 2^n x 2^n)
// Time Complexity : O(n^2)

using namespace std;

const int MAX = 100;

void copySubMatrix(int source[][MAX], int dest[][MAX], int startRow, int startCol, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            dest[i][j] = source[startRow + i][startCol + j];
        }
    }
}

void matrixMultiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    // A[m][n] times B[n][p] results in C[m][p]
    // C[MAX][MAX] is initialized by zeros

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void initizializeZeros(int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
}

// n is an exact power of 2
void matrixMultiplyRecursive(int A[][MAX],int B[][MAX],int C[][MAX],int n) {
    if (n == 1) {
        C[0][0] += A[0][0] * B[0][0];
        return;
    } else if (n == 3) {
        matrixMultiply(A, B, C, n);
        return;
    }

    int half_n = ceil(static_cast<float>(n)/2.0);
    cout << "Half Value of n in the iteration : " << half_n << "\n";

    int A_11[MAX][MAX], A_12[MAX][MAX], A_21[MAX][MAX], A_22[MAX][MAX];
    int B_11[MAX][MAX], B_12[MAX][MAX], B_21[MAX][MAX], B_22[MAX][MAX];
    int C_11[MAX][MAX], C_12[MAX][MAX], C_21[MAX][MAX], C_22[MAX][MAX];

    copySubMatrix(A, A_11, 0, 0, half_n, half_n);
    copySubMatrix(A, A_12, 0, half_n, half_n, half_n);
    copySubMatrix(A, A_21, half_n, 0, half_n, half_n);
    copySubMatrix(A, A_22, half_n, half_n, half_n, half_n);

    copySubMatrix(B, B_11, 0, 0, half_n, half_n);
    copySubMatrix(B, B_12, 0, half_n, half_n, half_n);
    copySubMatrix(B, B_21, half_n, 0, half_n, half_n);
    copySubMatrix(B, B_22, half_n, half_n, half_n, half_n);

    initizializeZeros(C_11, half_n);
    initizializeZeros(C_12, half_n);
    initizializeZeros(C_21, half_n);
    initizializeZeros(C_22, half_n);

    matrixMultiplyRecursive(A_11, B_11, C_11, half_n);
    matrixMultiplyRecursive(A_11, B_12, C_12, half_n);
    matrixMultiplyRecursive(A_21, B_11, C_21, half_n);
    matrixMultiplyRecursive(A_21, B_12, C_22, half_n);
    matrixMultiplyRecursive(A_12, B_21, C_11, half_n);
    matrixMultiplyRecursive(A_12, B_22, C_12, half_n);
    matrixMultiplyRecursive(A_22, B_21, C_21, half_n);
    matrixMultiplyRecursive(A_22, B_22, C_22, half_n);

    for (int i = 0; i < half_n; ++i) {
        for (int j = 0; j < half_n; ++j) {
            C[i][j] += C_11[i][j];
            C[i][j + half_n] += C_12[i][j];
            C[i + half_n][j] += C_21[i][j];
            C[i + half_n][j + half_n] += C_22[i][j];
        }
    }
}


void displayMatrix(int M[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << "Value at (" << i << "," << j << ") : " << M[i][j]; 
            cout << M[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n = 7;

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (i + 1)*(j - 1);
        }
    }

    cout << "Matrix A :\n";
    displayMatrix(A, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = 2*i + (j + 1);
        }
    }

    cout << "Matrix B :\n";
    displayMatrix(B, n);

    initizializeZeros(C, n);

    // C = A*B
    matrixMultiplyRecursive(A, B, C, n);

    cout << "Product Matrix C :\n";
    displayMatrix(C, n);

    return 0;

}