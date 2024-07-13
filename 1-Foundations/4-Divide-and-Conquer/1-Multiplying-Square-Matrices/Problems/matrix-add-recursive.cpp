#include <bits/stdc++.h>

const int MAX = 100;

using namespace std;

void copySubMatrix(int source[][MAX], int dest[][MAX], int startRow, int startCol, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            dest[i][j] = source[startRow + i][startCol + j];
        }
    }
}


void initializeZeros(int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
}

// Add 2 matrices with the same n x n dimension (n = 3)
void matrixAdd(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Add 2 matrices with the same n x n dimension
void matrixAddRecursive(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    if (n == 1) {
        C[0][0] += A[0][0] + B[0][0];
        return;
    } else if (n == 3) {
        matrixAdd(A, B, C, n);
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

    initializeZeros(C_11, half_n);
    initializeZeros(C_12, half_n);
    initializeZeros(C_21, half_n);
    initializeZeros(C_22, half_n);

    matrixAddRecursive(A_11, B_11, C_11, half_n);
    matrixAddRecursive(A_12, B_12, C_12, half_n);
    matrixAddRecursive(A_21, B_21, C_21, half_n);
    matrixAddRecursive(A_22, B_22, C_22, half_n);

    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
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
    int n = 4;

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

    initializeZeros(C, n);

    // C = A*B
    matrixAddRecursive(A, B, C, n);

    cout << "Product Matrix C :\n";
    displayMatrix(C, n);

    return 0;
}