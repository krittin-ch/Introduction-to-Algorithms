#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> p, int n) {
    if (n == 0) return 0;

    int q = INT_MIN;

    for (int i = 0; i < n; i++) {
        q = max(q, p[i] + cutRod(p, n - (i + 1)));
    }

    return q;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = length.size();

    int maxSold = cutRod(price, n);

    cout << "Maximum Sold is " << maxSold << endl;

    return 0;
}