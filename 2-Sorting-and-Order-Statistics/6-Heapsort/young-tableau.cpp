#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

class YoungTableau {
    private :

        vector<int> dim;    // dimension of young tableau
        vector<int> arr;    // inputs array to construct young tableau
        vector<vector<int>> y_tab;  // 2d young tableau

        void constructYoungTableau() {
            int cols = dim[1];
            int rows = dim[0];

            y_tab.resize(rows, vector<int>(cols, MAX));

            int row = rows - 1;
            int col = cols - 1;

            for (int num : arr) {
                // cout << "START INSERTION : " << num << endl << endl;

                // cout << "INITIAL CONDITION OF : " << num << endl;
                // cout << "WITH row = " << row << endl;
                // cout << "WITH col = " << col << endl;

                insertYoungTabaleau(num, row, col);

                // cout << "FINISHED CONDITION : " << endl;
                // print();
                // cout << "END INSERTION : " << num << endl;
                // cout << endl;
            }
        }

        void swap_elements(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

    
    public :
        YoungTableau(vector<int> dimension, vector<int> array) : dim(dimension), arr(array) {
            constructYoungTableau();
        }

        void insertYoungTabaleau(int num, int row, int col) {
            if (y_tab[dim[0]-1][dim[1]-1] != MAX) {
                cout << "Tableau is full. Cannot insert more elements." << endl;
                return;
            }

            y_tab[row][col] = num;

            while (row > 0) {
                /*
                    1        2      3          4
                    5        6      7          8
                    9        INF    INF        INF
                    INF      INF    INF        0(current)

                    NEXT

                    1        2      3          4
                    5        6      7          8
                    9        INF    INF        0(current)
                    INF      INF    INF        INF
                */ 

                if (y_tab[row][col] < y_tab[row - 1][col]) {
                    swap(y_tab[row][col], y_tab[row - 1][col]);
                    insertYoungTabaleau(y_tab[row][col], row, col);
                    row--;
                } else {
                    break;
                }
            }

            while (col > 0) {
                /*
                    1        2            3            4
                    5        6            7            8
                    9        15           12(current)  INF 
                    INF      INF          INF          INF

                    NEXT

                    1        2            3            4
                    5        6            7            8
                    9        12(current)  15           INF 
                    INF      INF          INF          INF
                */
                if (y_tab[row][col] < y_tab[row][col - 1]) {
                    swap(y_tab[row][col], y_tab[row][col - 1]);
                    insertYoungTabaleau(y_tab[row][col], row, col);
                    col--;
                } else {
                    break;
                }
            }
        }

        int extractMin(int i, int j) {

            if (y_tab[i][j] == MAX) {
                cout << "Tableau is empty. Cannot extract elements." << endl;
                return MAX;
            }
            
            cout << "HIIIIIIIIIII\n";
            int min = y_tab[i][j];
            
            if (y_tab[i][j + 1] == y_tab[i + 1][j] && y_tab[i + 1][j] == MAX) {
                y_tab[i][j] = MAX;
                return min;
            }

            // if (y_tab[i][j + 1] < y_tab[i + 1][j]) {
            //     y_tab[i][j] = y_tab[i][j + 1];
            //     y_tab[i][j + 1] = min;
            //     return extractMin(i, j + 1);
            // } else {
            //     y_tab[i][j] = y_tab[i + 1][j];
            //     y_tab[i + 1][j] = min;
            //     return extractMin(i + 1, j);
            // }
            return y_tab[i][j + 1];
        }

        void print() {
            for (const auto& row : y_tab) {
                for (int elem : row) {
                    if (elem == MAX) {
                        cout << "__ ";
                        // cout << elem << " ";
                    } else {
                        cout << elem << " ";
                    }
                }
                cout << endl;
            }
        }
};

int main() {
    srand(time(0));
    int rows = 4;
    int cols = 4;
    
    vector<int> dimension = {rows, cols};  // 4x4 Young tableau
    vector<int> array = {9, 16, 3, 2, 4, 8, 5, 14, 12};

    

    YoungTableau yt(dimension, array);
    cout << "Original Tableau :" << endl;
    yt.print();

    // Insert additional elements
    yt.insertYoungTabaleau(1, rows - 1, cols - 1);
    yt.insertYoungTabaleau(7, rows - 1, cols - 1);
    cout << "After inserting 1 and 7:" << endl;
    yt.print();

    int mini = yt.extractMin(0, 0);

    cout << "MINI : " << mini << endl;
    yt.print();

    return 0;
}
