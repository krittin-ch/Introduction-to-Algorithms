#include <bits/stdc++.h>

using namespace std;

int bottomUpCutRod(const vector<int>& p, int n) {
    vector<int> r(n + 1, 0);

    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = max(q, p[i - 1] + r[j - i]);
        }
        r[j] = q;
    }

    return r[n];
}

struct RodResult {
    vector<int> r;
    vector<int> s;

    RodResult(int n_plus_one): r(n_plus_one), s(n_plus_one) {}
};

RodResult extendedBottomUpCutRod(vector<int> p, int n) {
    vector<int> r(n + 1);
    vector<int> s(n + 1);

    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            if (q < p[i - 1] + r[j - i]) {
                q = p[i - 1] + r[j - i];
                s[j] = i;
            }
        }

        r[j] = q;
    }

    RodResult result(n);
    result.r = r;
    result.s = s;

    return result;
}

void printCutRodSolution(vector<int> p, int n) {
    RodResult rodRes = extendedBottomUpCutRod(p, n);

    vector<int> s = rodRes.s;

    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = length.size();

    int maxSold = bottomUpCutRod(price, n);

    cout << "Maximum Sold is " << maxSold << endl << endl;

    printCutRodSolution(price, n);

    return 0;
}