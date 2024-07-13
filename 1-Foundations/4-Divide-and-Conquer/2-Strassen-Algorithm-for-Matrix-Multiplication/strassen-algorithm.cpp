#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
/*
    1 (4 x 4) Matrix requires 4 bytes x 100 x 100 = 40 KB
    Although the memory required size is small, this could lead to stack overflow,
    i.e. there is no memory space for an array - a matrix - to store contiguously.
*/

void initializeZeros(int C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
}

void copySubMatrix(int source[][MAX], int dest[][MAX], int startRow, int startCol, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            dest[i][j] = source[startRow + i][startCol + j];
        }
    }
}

void matrixAdd(int A[][MAX], int B[][MAX], int S[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrixSubstract(int A[][MAX], int B[][MAX], int S[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            S[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenAlgorithm(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A_11[MAX][MAX], A_12[MAX][MAX], A_21[MAX][MAX], A_22[MAX][MAX];
    int B_11[MAX][MAX], B_12[MAX][MAX], B_21[MAX][MAX], B_22[MAX][MAX];
    int C_11[MAX][MAX], C_12[MAX][MAX], C_21[MAX][MAX], C_22[MAX][MAX];
    
    int half_n = ceil(static_cast<float>(n)/2.0);
    cout << "Half Value of n in the iteration : " << half_n << endl;

    copySubMatrix(A, A_11, 0, 0, half_n, half_n);
    copySubMatrix(A, A_12, 0, half_n, half_n, half_n);
    copySubMatrix(A, A_21, half_n, 0, half_n, half_n);
    copySubMatrix(A, A_22, half_n, half_n, half_n, half_n);
    
    copySubMatrix(B, B_11, 0, 0, half_n, half_n);
    copySubMatrix(B, B_12, 0, half_n, half_n, half_n);
    copySubMatrix(B, B_21, half_n, 0, half_n, half_n);
    copySubMatrix(B, B_22, half_n, half_n, half_n, half_n);
    
    int S_1[MAX][MAX], S_2[MAX][MAX], S_3[MAX][MAX], S_4[MAX][MAX], S_5[MAX][MAX];
    int S_6[MAX][MAX], S_7[MAX][MAX], S_8[MAX][MAX], S_9[MAX][MAX], S_10[MAX][MAX];
    
    matrixSubstract(B_12, B_22, S_1, half_n);
    matrixAdd(A_11, A_12, S_2, half_n);
    matrixAdd(A_21, A_22, S_3, half_n);
    matrixSubstract(B_21, B_11, S_4, half_n);
    matrixAdd(A_11, A_22, S_5, half_n);
    matrixAdd(B_11, B_22, S_6, half_n);
    matrixSubstract(A_12, A_22, S_7, half_n);
    matrixAdd(B_21, B_22, S_8, half_n);
    matrixSubstract(A_11, A_21, S_9, half_n);
    matrixAdd(B_11, B_12, S_10, half_n);
    
    int P_1[MAX][MAX], P_2[MAX][MAX], P_3[MAX][MAX];
    int P_4[MAX][MAX], P_5[MAX][MAX], P_6[MAX][MAX], P_7[MAX][MAX];

    strassenAlgorithm(A_11, S_1, P_1, half_n);
    strassenAlgorithm(S_2, B_22, P_2, half_n);
    strassenAlgorithm(S_3, B_11, P_3, half_n);
    strassenAlgorithm(A_22, S_4, P_4, half_n);
    strassenAlgorithm(S_5, S_6, P_5, half_n);
    strassenAlgorithm(S_7, S_8, P_6, half_n);
    strassenAlgorithm(S_9, S_10, P_7, half_n);


    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
            C_11[i][j] = P_5[i][j] + P_4[i][j] - P_2[i][j] + P_6[i][j];
            C_12[i][j] = P_1[i][j] + P_2[i][j];
            C_21[i][j] = P_3[i][j] + P_4[i][j];
            C_22[i][j] = P_5[i][j] + P_1[i][j] - P_3[i][j] - P_7[i][j];
        }
    }

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
        cout << endl;
    }
    cout << endl;
}

int main() {

    int n = 4;

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (i + 1)*(j - 1);
        }
    }
    
    cout << "Matrix A :" << endl;
    displayMatrix(A, n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = 2*i + (j + 1);
        }
    }
    
    cout << "Matrix B :" << endl;
    displayMatrix(B, n);

    initializeZeros(C, n);

    strassenAlgorithm(A, B, C, n);
    cout << "Product Matrix C :" << endl;
    displayMatrix(C, n);

    return 0;

}