#include <bits/stdc++.h>

using namespace std;

int rowMajorOrderIndex(int i, int j, int n) {
    // row-major order, the matrix is stored row by row
    // "i" refers to row and "j" refers to column
    // if the starting index is "s" then at row "i" and column "j"
    // idx = s + (n*(i - s)) + (j - s) while n is the number of columns

    // for s = 0, idx = n*i + j

    /*
        Row-Major Order : 
            1 2 3 4 
            5 6 7 8 
            9 10 11 12 
    */

    return n*i + j;
}

int columnMajorOrderIndex(int i, int j, int m) {
    // column-major order, the matrix is stored column by column
    // "i" refers to row and "j" refers to column
    // if the starting index is "s" then at row "i" and column "j"
    // idx = s + (m*(j - s)) + (i - s) while m is the number of rows

    // for s = 0, idx = m*j + i

    /*
        Column-Major Order : 
            1 4 7 10 
            2 5 8 11 
            3 6 9 12 
    */

    return m*j + i;
}

void displayMatrix(int arr[], int rows, int cols, bool rowOrder) {
    if (rowOrder) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = rowMajorOrderIndex(i, j, cols);
                cout << arr[idx] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = columnMajorOrderIndex(i, j, rows);
                cout << arr[idx] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    bool rowOrder = true;
    int rows = 3;
    int cols = 4;

    cout << "Row-Major Order : " << endl;
    displayMatrix(arr, rows, cols, rowOrder);

    cout << "Column-Major Order : " << endl;
    displayMatrix(arr, rows, cols, !rowOrder);

    return 0;
}