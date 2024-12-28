#include <bits/stdc++.h>

using namespace std;

int memoizedCutRodAux(vector<int> p, int n, vector<int> r) {
    if (r[n] >= 0) return r[n]; // already have a solution fr length n?

    int q;

    if (n == 0) {
        q = 0;
    } else {
        q = INT_MIN;
        
        for (int i = 0; i < n; i++) {   // i is the position of the first cut
            q = max(q, p[i] + memoizedCutRodAux(p, n - (i + 1), r));
        }
    }

    r[n] = q;   // remember the solution value for length n

    return q;
}

int memorizedCutRod(vector<int> p, int n) {
    vector<int> r(n + 1, INT_MIN);

    return memoizedCutRodAux(p, n, r);
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = length.size();

    int maxSold = memorizedCutRod(price, n);

    cout << "Maximum Sold is " << maxSold << endl;

    return 0;
}