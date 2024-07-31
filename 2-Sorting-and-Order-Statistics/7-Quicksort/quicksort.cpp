#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &vec, int p, int r) {
    /*
        Example :
            
        Start  : 9 16 3 2 4 8 5 14 12(pivot) 
        
        Finish : 9 3 2 4 8 5 12(pivot) 14 16 
    */ 
    int pivot = vec[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (vec[j] < pivot) {
            swap(vec[++i], vec[j]);
        }
    }
    swap(vec[++i], vec[r]);

    return i;
}

void quickSort(vector<int> &vec, int p, int r) {
    // Allowing the recursivee call to terminate
    if (p > r) {
        return;
    }

    int q = partition(vec, p, r);

    quickSort(vec, p, q - 1);
    quickSort(vec, q + 1, r);
}

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {9, 16, 3, 2, 4, 8, 5, 14, 12};
    // vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    cout << "Original Array : " << endl;
    displayArray(vec);
    partition(vec, 0, vec.size() - 1);



    // quickSort(vec, 0, vec.size() - 1);

    cout << "Sorted Array : " << endl;
    displayArray(vec);
}