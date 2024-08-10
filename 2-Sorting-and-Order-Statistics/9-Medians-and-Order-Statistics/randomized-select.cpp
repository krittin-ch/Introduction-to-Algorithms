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
    int j = p;

    while (j < r) {
        if (vec[j] < vec[r]) {
            swap(vec[++i], vec[j]);
        }
        j++;
    }
    
    swap(vec[++i], vec[r]);

    return i;
}
int randomizedPartition(vector<int> &vec, int p, int r) {
    int length = p - r + 1;

    if (length > 1) {
        int index = rand() % length;
        swap(vec[index], vec[r]);
    }
    // cout << "PIVOT : " << pivot << endl;

    return partition(vec, p, r);
}

int randomizedSelect(vector<int> &vec, int p, int r, int i) {
    if (p == r) {
        return vec[p];
    }

    int q = randomizedPartition(vec, p, r);
    displayArray(vec);
    int k = q - p + 1;

    cout << "K = " << k << endl;

    if (i == k) {
        return vec[q];
    } else if (i < k) {
        return randomizedSelect(vec, p, q - 1, i);
    } else {
        return randomizedSelect(vec, q + 1, r, i - k);
    }
}

int main() {
    srand(time(0));
    vector<int> vec = {4, 3, 2, 6, 1, 5, 10, 8, 7, 9};

    int order = 6;

    int num = randomizedSelect(vec, 0, vec.size() - 1, order);

    cout << order << "-th order : " << num << endl;

    return 0;
}