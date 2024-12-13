#include <bits/stdc++.h>

using namespace std;

int binaryTreeCombinations(int n) {
    if (n == 0) return 1;

    int res = 0;

    for (int k = 0; k < n; k++) {
        res += binaryTreeCombinations(k) * binaryTreeCombinations(n-1-k);
    }

    return res;
}

int main() {
    int n = 5;

    cout << "Number of Different Binary Trees:" << endl;
    cout << binaryTreeCombinations(n);
}