#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    } 
    cout << endl;
}

/*
    0-1 Sorting Lemma

    If an oblivious comparison-exchange algorithm correctly sorts all inputs sequences consisting of only 0s and 1s, 
    then it correctly sorts all inputs containing arbitrary values.
*/

/*
    Oblivious Compare-Exchange Algorithm

    It operates solely by a sequence of prespecified compare-exchange operations.
    
    The indices of the positions compared in the sequence msut be determined in advance, 
    and although they can depend on the number of elements being sorted, they cannot depend on the values being sorted, 
    nor can they depend on the result of any prior compare-exchange operation.
*/

void compareExchange(vector<int> &vec, int i, int j) {
    if (vec[i] > vec[j]) swap(vec[i], vec[j]);
}

void compareExchangeInsertionSort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            compareExchange(vec, j, j + 1);
        }
    }
}

int main() {
    vector<int> vec = {0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1};
    // vector<int> vec = {2, 5, 1, 8, 4, 3, 12, 6};

    cout << "Original Array : ";
    displayArray(vec);

    cout << "Sorted Array : ";
    compareExchangeInsertionSort(vec);
    displayArray(vec);
}