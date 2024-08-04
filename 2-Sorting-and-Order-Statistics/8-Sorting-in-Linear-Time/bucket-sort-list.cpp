#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<float> vec) {
    for (float num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void displayList(list<float> ls) {
    list<float>::iterator it;
    for (it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void copyToVector(vector<float> &vec, list<float> ls) {
    list<float>::iterator it;
    for (it = ls.begin(); it != ls.end(); it++) {
        vec.push_back(*it);
    }
}

void bucketSort(vector<float> &vec) {
    vector<list<float>> bucket(10);

    for (float num : vec) {
        int index = 10 * num;
        bucket[index].push_back(num);
    }

    vec.clear();
    for (list<float> ls : bucket) {
        ls.sort();
        copyToVector(vec, ls);
    }
}

int main() {
    vector<float> vec = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original Array : " << endl;
    displayArray(vec);

    bucketSort(vec);
    cout << "Sorted Array : " << endl;
    displayArray(vec);

    return 0;
}