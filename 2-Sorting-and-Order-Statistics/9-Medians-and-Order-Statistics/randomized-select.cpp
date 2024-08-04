#include <bits/stdc++.h>

using namespace std;

int randomizedPartition(vector<int> &vec, int p, int r) {
    int index = rand() % (vec.size() - 1);
    int pivot = vec[index];
    // cout << "PIVOT : " << pivot << endl;

    swap(vec[index], vec[r]);

    int i = p - 1;
    int j = p;

    while (j < r) {
        if (vec[j] < pivot) {
            swap(vec[j], vec[++i]);
        }
        j++;
    }
    swap(vec[++i], vec[r]);

    return j;
}

int randomizedSelect(vector<int> vec, int p, int r, int i) {
    if (p == r) {
        return vec[p];
    }
    int q = randomizedPartition(vec, p, r);
    int k = q - p + 1;

    if (i == k) {
        return vec[q];
    } else if (i < k) {
        return randomizedSelect(vec, p, q, i);
    } else {
        return randomizedSelect(vec, q + 1, r, i - k);
    }
}

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    vector<int> vec = {1, 4, 2, 5, 7, 9, 3, 6};

    randomizedPartition(vec, 0, vec.size() - 1);

    displayArray(vec);

    int min = randomizedSelect(vec, 0, vec.size() - 1, 6);

    cout << "MINIMUM : " << min << endl;

    return 0;
}