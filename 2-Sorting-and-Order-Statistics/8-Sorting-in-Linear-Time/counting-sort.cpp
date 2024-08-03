#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> countingSort(vector<int> vec, int n, int k) {
    vector<int> B(n, 0);
    vector<int> C(k + 1, 0);

    for (int j = 0; j < n; j++) {
        C[vec[j]]++;
    }

    // cout << "Array C (State I) : " << endl;
    // displayArray(C);

    for (int i = 1; i < k + 1; i++) {
        C[i] += C[i - 1];
    }

    // cout << "Array C (State II) : " << endl;
    // displayArray(C);

    for (int j = n - 1; j >= 0; j--) {
        B[C[vec[j]] - 1] = vec[j];
        C[vec[j]]--;
    }

    return B;
}


void modifiedCountingSort(vector<int> &vec, int n, int k) {
    vector<int> C(k + 1, 0);

    for (int j = 0; j < n; j++) {
        C[vec[j]]++;
    }

    cout << "Array C : " << endl;
    displayArray(C);

    int i = 0;

    for (int j = 0; j < C.size(); ++j) {
        while (C[j] > 0) {
            vec[i++] = j;
            C[j]--;
        }
    }
}


int main() {
    vector<int> vec = {1, 5, 3, 4, 8, 3, 2, 12, 3, 2, 1};

    cout << "Original Array : " << endl;
    displayArray(vec);

    vector<int> B = countingSort(vec, vec.size(), 12);
    cout << "Sorted Array : " << endl;
    displayArray(B);
    
    modifiedCountingSort(vec, vec.size(), 12);
    cout << "Sorted Array : " << endl;
    displayArray(vec);
    

    return 0;
}