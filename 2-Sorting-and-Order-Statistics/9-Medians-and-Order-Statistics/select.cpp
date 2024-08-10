#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &vec, int start, int step) {
    for (int i = 1; i <= 4; i++) {
        int key = vec[start + step * i];
        int j = i - 1;

        while (j >= 0 && vec[start + step * j] > key) {
            vec[start + step * (j + 1)] = vec[start + step * j];
            j--;
        }
        vec[start + step * (j + 1)] = key;
    }
}

int partitionAround(vector<int> &vec, int p, int r, int x) {
    int idx = 0;

    while (vec[idx] != x) {
        idx++;
    }

    swap(vec[idx], vec[r]);

    int i = p - 1;
    int j = p;

    while (j < r) {
        if (vec[j] < x) {
            swap(vec[++i], vec[j]);
        }
        j++;
    }

    swap(vec[++i], vec[r]);

    return i;
}

int select(vector<int> &vec, int p, int r, int i) {
    i--;
    while ((r - p) % 5 != 0) {
        for (int j = p + 1; j < r; j++) {
            if (vec[p] > vec[j]) {
                swap(vec[p], vec[j]);
            }
        }

        if (i == 0) return vec[p];

        p++;
        i--;
    }
    
    int g = (r - p) / 5;
    for (int j = p; j < p + g - 1; j++) {
        insertionSort(vec, j, g);
    }

    int x = select(vec, p + 2*g, p + 3*g - 1, ceil(g/2));
    int q  = partitionAround(vec, p, r, x);

    int k = q - p + 1;

    if (i == k) {
        return vec[q];
    } else if (i < k) {
        return select(vec, p, q - 1, i);
    } else {
        return select(vec, q + 1, r, i - k);
    }

}

int main() {
    vector<int> vec = {4, 3, 2, 6, 1, 5, 10, 8, 7, 9};
    
    int order = 4;

    int num = select(vec, 0, vec.size() - 1, order);

    cout << order << "-th order : " << num << endl;

    return 0;
}