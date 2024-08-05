#include <bits/stdc++.h>

using namespace std;

void displayMatrix(vector<vector<int>> vec) {
    for (vector<int> sub_vec: vec) {
        for (int num : sub_vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkDimension(vector<vector<int>> vec) {
    int r = vec.size();
    int s = vec[0].size();

    if (
        r % 2 != 0 &&
        r % s != 0 &&
        2*pow(s, 2) > r
    ) {
        return false;
    }

    return true;
}

void comparisonExchange(vector<int> &vec, int i, int j) {
    if (vec[i] > vec[j]) swap(vec[i], vec[j]);
}

void comparisonExchangeInsertionSort(vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            comparisonExchange(vec, j, j + 1);
        }
    }
}

// Step 1, 3, and 5
void columnSort(vector<vector<int>> &vec) {
    vector<int> col_vec;

    for (int i = 0; i < vec[0].size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            col_vec.push_back(vec[j][i]);
        }

        comparisonExchangeInsertionSort(col_vec);
        for (int j = 0; j < vec.size(); j++) {
            vec[j][i] = col_vec[j];
        }
        col_vec.clear();
    }
}

// Step 2
void transpose(vector<vector<int>> &vec) {
    vector<vector<int>> vec_t(vec[0].size(), vector<int>(vec.size()));

    for (int i = 0; i < vec[0].size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            vec_t[i][j] = vec[j][i];
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            int i_t = i / (vec.size() / vec_t.size());
            int j_t = j + vec_t.size() * (i % (vec.size() / vec_t.size()));

            // cout << "i = " << i << endl;
            // cout << "j = " << j << endl;
            // cout << "i_t = " << i_t << endl;
            // cout << "j_t = " << j_t << endl << endl;

            vec[i][j] = vec_t[i_t][j_t];
        }
    }
}

// Step 4
void inverseTranspose(vector<vector<int>> &vec) {
    vector<vector<int>> vec_in_t(vec[0].size(), vector<int>(vec.size()));

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            int i_t = i / (vec.size() / vec_in_t.size());
            int j_t = j + vec_in_t.size() * (i % (vec.size() / vec_in_t.size()));

            // cout << "i = " << i << endl;
            // cout << "j = " << j << endl;
            // cout << "i_t = " << i_t << endl;
            // cout << "j_t = " << j_t << endl << endl;

            vec_in_t[i_t][j_t] = vec[i][j]; 
        }
    }

    for (int i = 0; i < vec[0].size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            vec[j][i] = vec_in_t[i][j];
        }
    }
}

// Step 6
void shiftAndColumnSort(vector<vector<int>> &vec) {
    vector<vector<int>> vec_n(vec.size(), vector<int>(vec.size() + 1));

    for (int i = 0; i < vec_n.size() / 2; i++) {
        vec_n[i][0] = 0;
        vec_n[vec_n.size() - i][vec_n[0].size() - 1] = INT_MAX;
    }

    for (int i = 0; i < vec_n.size(); i++) {
        for (int j = 0; j < vec_n[0].size(); j++) {
            vec_n[i][j] = 10;
        }
    }

    displayMatrix(vec_n);
}

vector<vector<int>> completeColumnSort(vector<vector<int>> &vec) {
    
    cout << "Original Matrix : " << endl;
    displayMatrix(vec);

    cout << "Sorted Matrix (State I) : " << endl;
    columnSort(vec);
    displayMatrix(vec);


    cout << "Transpose Matrix : " << endl;
    transpose(vec);
    displayMatrix(vec);

    cout << "Sorted Matrix (State II) : " << endl;
    columnSort(vec);
    displayMatrix(vec);

    cout << "Inverse Transpose Matrix : " << endl;
    inverseTranspose(vec);
    displayMatrix(vec);

    cout << "Sorted Matrix (State III) : " << endl;
    columnSort(vec);
    displayMatrix(vec);

    shiftAndColumnSort(vec);

    return vec;
}

int main() {
    int r = 6;
    int s = 3;

    // vector<vector<int>> vec(r, vector<int>(s));

    vector<vector<int>> vec = {
        {10, 14, 5},
        {8, 7, 17},
        {12, 1, 6},
        {16, 9, 11},
        {4, 15, 2},
        {18, 3, 13}
    };

    if (!checkDimension(vec)) {
        cout << "Error Dimension";
        return 1;
    }

    completeColumnSort(vec);

    return 0;
}