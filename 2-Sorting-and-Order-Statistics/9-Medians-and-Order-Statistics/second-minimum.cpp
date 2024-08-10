#include <bits/stdc++.h>

using namespace std;

void displayArray(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;
}

/*
    With divide-and-conquer algorithm

    T(n) = T(n/2) + n/2 + 1

    T(n/2)  : the size of subproblems
    n/2     : n/2 comparisons * O(1)
    1       : combing result time

    T(n) = n + ceil(lg 2) - 2
*/

vector<int> secondSmallest(vector<int> vec) {
    if (vec.size() <= 2) {
        sort(vec.begin(), vec.end());
        return vec;
    }

    int mid = vec.size() / 2;

    vector<int> vec1(vec.begin(), vec.begin() + mid);
    vector<int> vec2(vec.begin() + mid, vec.end());
    

    vector<int> arr1 = secondSmallest(vec1);
    vector<int> arr2 = secondSmallest(vec2);

    int i = 0;
    int j = 0;

    vector<int> ans;

    while (ans.size() != 2 && i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (ans.size() < 2 && i < arr1.size()) {
        ans.push_back(arr1[i]);
        i++;
    }

    while (ans.size() < 2 && j < arr2.size()) {
        ans.push_back(arr2[j]);
        j++;
    }


    return ans;
}


int main() {
    vector<int> vec = {13, 4, 2, 7, 3, 8, 1, 11, 5, -2, 4, 0};

    vector<int> two_smallest = secondSmallest(vec);

    cout << "Smallest Value : " << two_smallest[0] << endl;

    cout << "Second Smallest Value : " << two_smallest[1] << endl;

    return 0;
}