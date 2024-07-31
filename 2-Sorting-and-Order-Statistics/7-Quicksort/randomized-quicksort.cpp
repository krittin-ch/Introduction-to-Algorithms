#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int> &vec, int p, int r) {
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

int randomizedPartition(vector<int>& vec, int p, int r) {
    int length = r - p + 1;
    
    // Ensure length is at least 1
    if (length > 1) { 
        int idx = p + rand() % length;
        swap(vec[r], vec[idx]);
    }
    
    return partition(vec, p, r);
}

void randomizedQuicksort(vector<int> &vec, int p, int r) {
    if (p >= r) {
        return;
    }

    int q = randomizedPartition(vec, p, r);
    
    randomizedQuicksort(vec, p, q - 1);
    randomizedQuicksort(vec, q + 1, r);
}


int main() {
    srand(time(0));
    
    // vector<int> vec = {2, 63, 6, 1, 21, 41, 12, 11};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    cout << "Original Array : " << endl;
    displayArray(vec);


    randomizedQuicksort(vec, 0, vec.size() - 1);
    cout << "Sorted Array : " << endl;
    displayArray(vec);

    return 0;
}