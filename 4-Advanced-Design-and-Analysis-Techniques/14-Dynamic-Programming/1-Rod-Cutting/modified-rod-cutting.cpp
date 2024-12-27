#include <bits/stdc++.h>

using namespace std;

struct RodResult {
    vector<int> r;
    vector<int> s;

    RodResult(int n_plus_one) : r(n_plus_one), s(n_plus_one) {}
};

RodResult bottomUpCutRod(vector<int> p, int n, int c) {
    vector<int> r(n + 1);
    vector<int> s(n + 1);

    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            int profit = p[i - 1] + r[j - i] - c;
            if (q < profit) {
                q = profit;
                s[j] = i;
            }
        }

        r[j] = q;
    }

    RodResult result(n + 1);
    result.r = r;
    result.s = s;

    return result;
}

void printCutRodSolution(vector<int> p, int n, int c) {
    RodResult rodRes = bottomUpCutRod(p, n, c);
    vector<int> s = rodRes.s;

    cout << "Rod Cutting Solution: ";

    int len = n;
    while (len > 0) {
        cout << s[len] << " ";
        len -= s[len];
    }

    cout << endl;
    cout << "Rod Cutting Profit: " << rodRes.r[n] << endl;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = length.size();
    int c = 1;

    printCutRodSolution(price, n, c);

    return 0;
}