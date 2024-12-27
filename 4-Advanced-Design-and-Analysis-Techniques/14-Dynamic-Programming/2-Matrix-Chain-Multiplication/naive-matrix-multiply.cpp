#include <bits/stdc++.h>
using namespace std;

void rectangularMatrixMultiply(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int p, int q, int r) {
    if (A.size() != p || B.size() != q || A[0].size() != q || B[0].size() != r) {
        cout << "Matrix dimensions are invalid for multiplication." << endl;
        return;
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int p = 3, q = 4, r = 3;

    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<vector<int>> B = {
        {-1, 2, 4},
        {-3, -6, -1},
        {0, 0, 3},
        {12, 32, 0}
    };

    vector<vector<int>> C(p, vector<int>(r, 0));

    rectangularMatrixMultiply(A, B, C, p, q, r);

    cout << "Resultant Matrix C:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
