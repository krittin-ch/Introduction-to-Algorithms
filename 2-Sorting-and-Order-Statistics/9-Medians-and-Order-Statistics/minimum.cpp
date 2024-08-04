#include <bits/stdc++.h>

using namespace std;

int minimum(vector<int> vec) {
    int min = vec[0];
    for (int num : vec) {
        if (min > num) {
            min = num;
        }
    }

    return min;
}

int main() {
    vector<int> vec = {1, 4, 2, 7, 3, 5, 6, 10, 8};

    int min = minimum(vec);

    cout << "Minimum Value : " << min;
    
    return 0;
}