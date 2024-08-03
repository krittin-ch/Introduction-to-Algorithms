#include <bits/stdc++.h>

using namespace std;

int getMax(vector<int> &vec) {
    return *max_element(vec.begin(), vec.end());
}

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void countingSort(vector<int> &vec, int exp) {
    int n = vec.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        int digit = (vec[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (vec[i] / exp) % 10;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}

void radixSort(vector<int> &vec) {
    int maxVal = getMax(vec);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(vec, exp);
    }
}

int main() {
    vector<int> vec = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array : " << endl;
    displayArray(vec);
    
    /*
    countingSort(vec, 1);
    cout << "Sorted First Index : " << endl;
    displayArray(vec);
    
    countingSort(vec, 10);
    cout << "Sorted Second Index : " << endl;
    displayArray(vec);

    countingSort(vec, 100);
    cout << "Sorted Third Index : " << endl;
    displayArray(vec);
    */ 
   
    radixSort(vec);
    cout << "Radix Sorted Array : " << endl;
    displayArray(vec);
    
    return 0;
}