#include <bits/stdc++.h>

using namespace std;

class BinaryMatrix {
    private:
        // vector input of size 4
        static const int MAX_SIZE = 4;
        vector<int> vec;
        
        // sub-matrix dimension
        int rows;
        int cols;
        int numEle = rows*cols;
        
        vector<vector<int>> binaryVec;

        bool checkCondition() {
            if (vec.size() != MAX_SIZE) return false;

            for (int num : vec) {
                if (num > pow(2, rows * cols) - 1) {
                    return false;
                }
            }

            return true;
        }


    public:
        BinaryMatrix(vector<int> values, int numRows, int numCols) 
        : vec(values), rows(numRows), cols(numCols), numEle(numRows * numCols) {
            constructBinaryMatrix();
        }

        void constructBinaryMatrix() {
            if (!checkCondition()) {
                cout << "Error Occurs from the Input Array";
                return;
            }

            for (int i = 0; i < vec.size(); i++) {
                int numLength = log2(vec[i]) + 1;
                int numLeftOver = numEle - numLength;
            
                vector<int> binaryRow(numEle, 0);

                int dummy = vec[i];

                for (int j = numLength; j >= 0; j--) {
                    if (dummy - pow(2, j) >= 0) {
                        binaryRow[numEle - 1 - j] = 1;
                        dummy -= pow(2, j);
                    } else {
                        binaryRow[numEle - 1 - j] = 0;
                    }
                }

                binaryVec.push_back(binaryRow);
            }
        }

        void displayBinaryArray() {
            for (vector<int> x : binaryVec) {
                for (int num : x) {
                    cout << num << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        void displayBinaryMatrix() {
            for (int x = 0; x < cols*2; x++) {
                for (int y = 0; y < rows*2; y++) {
                    int i = x % cols;
                    int j = y % rows;
                    int blockSize = cols * rows;
                    int blockShift = (y / rows + 2*(x / cols))*blockSize;
                    
                    // cout << binaryVec[i][j] << " ";

                    cout << i << " " << j << "X " << blockShift << "XXX" << "   ";

                }
                cout << "|" << endl;
            }
            cout << endl;
        }

};

int main() {
    vector<int> vec = {4, 5, 2, 13};

    BinaryMatrix biMat(vec, 2, 4);

    // biMat.displayBinaryArray();

    biMat.displayBinaryMatrix();
    return 0;
}