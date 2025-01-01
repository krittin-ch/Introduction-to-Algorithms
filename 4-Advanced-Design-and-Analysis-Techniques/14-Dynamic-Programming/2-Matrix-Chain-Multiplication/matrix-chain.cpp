#include <bits/stdc++.h>
using namespace std;

void fillRandom2D(vector<vector<float>> &mat) {
    static mt19937 rng(random_device{}()); 
    static uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (auto &row : mat) {
        for (auto &val : row) {
            val = dist(rng);
        }
    }
}

struct AuxTable {
    vector<vector<int>> m;  // m[1:n, 1:n]
    vector<vector<int>> s;  // s[1:n-1, 2:n]

    AuxTable(int n_matrices) : m(n_matrices, vector<int>(n_matrices)), s(n_matrices - 1, vector<int>(n_matrices - 1)) {}
};

AuxTable matrixChainOrder(vector<int> p, int n) {
    AuxTable aux_tab = AuxTable(n);
    vector<vector<int>>& m = aux_tab.m;
    vector<vector<int>>& s = aux_tab.s;

    for (int i = 1; i <= n; i++) {
        m[i - 1][i - 1] = 0;
    }
    
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i - 1][j - 1] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
                if (q < m[i - 1][j - 1]) {
                    m[i - 1][j - 1] = q;
                    s[i - 1][j - 2] = k;    
                }
            }
        }
    }

    return aux_tab;
}

void printMatrix(vector<vector<int>> A) {
    for (vector<int> vec : A) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printOptimalParens(vector<vector<int>> s, int i, int j) {
    if (i == j) {
        cout << "A" << i; 
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i - 1][j - 2]);
        printOptimalParens(s, s[i - 1][j - 2] + 1, j);
        cout << ")";
    }
}

vector<vector<float>> matrixMultiply(const vector<vector<float>>& A, 
                                     const vector<vector<float>>& B)
{
    // Check dimensions: A is p x q, B must be q x r to be multipliable
    if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) {
        throw invalid_argument("Matrices must not be empty.");
    }
    if (A[0].size() != B.size()) {
        throw invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    
    // p x q times q x r => p x r result
    int p = A.size();        // number of rows in A
    int q = A[0].size();     // number of columns in A (also rows in B)
    int r = B[0].size();     // number of columns in B

    // Create the result matrix with p rows and r columns, initialized to 0
    vector<vector<float>> C(p, vector<float>(r, 0.0f));

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<int>> matrixChainMultiply(vector<vector<float>> mat, vector<vector<int>> s, int i, int j) {
    if (i == j ) {
        
    }
}

int main() {
    int p1 = 30;
    int p2 = 35;
    int p3 = 15;
    int p4 = 5;
    int p5 = 10;
    int p6 = 20;
    int p7 = 25;

    vector<int> p = {p1, p2, p3, p4, p5, p6, p7};
    const int n = p.size() - 1;

    vector<vector<float>> A1(p1, vector<float>(p2));
    vector<vector<float>> A2(p2, vector<float>(p3));
    vector<vector<float>> A3(p3, vector<float>(p4));
    vector<vector<float>> A4(p4, vector<float>(p5));
    vector<vector<float>> A5(p5, vector<float>(p6));
    vector<vector<float>> A6(p6, vector<float>(p7));

    vector<vector<vector<float>>> M = {A1, A2, A3, A4, A5, A6};

    fillRandom2D(A1);
    fillRandom2D(A2);
    fillRandom2D(A3);
    fillRandom2D(A4);
    fillRandom2D(A5);
    fillRandom2D(A6);

    AuxTable aux_tab = matrixChainOrder(p, n);

    vector<vector<int>> m = aux_tab.m;
    vector<vector<int>> s = aux_tab.s;

    printMatrix(m);
    printMatrix(s);

    printOptimalParens(s, 1, 6);

    return 0;
}
