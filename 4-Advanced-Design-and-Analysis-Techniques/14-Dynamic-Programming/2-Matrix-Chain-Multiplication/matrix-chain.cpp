#include <bits/stdc++.h>
using namespace std;

void fillRandom2D(vector<vector<float>> &mat) {
    static mt19937 rng(random_device{}()); 
    static uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (auto &row : mat) {
        for (auto &val : row) {
            val = dist(rng);
        }
    }
}

int main() {
    // Correctly initialize each dimension
    int p1 = 30;
    int p2 = 35;
    int p3 = 15;
    int p4 = 5;
    int p5 = 10;
    int p6 = 20;
    int p7 = 25;

    vector<vector<float>> A1(p1, vector<float>(p2));
    vector<vector<float>> A2(p2, vector<float>(p3));
    vector<vector<float>> A3(p3, vector<float>(p4));
    vector<vector<float>> A4(p4, vector<float>(p5));
    vector<vector<float>> A5(p5, vector<float>(p6));
    vector<vector<float>> A6(p6, vector<float>(p7));

    fillRandom2D(A1);
    fillRandom2D(A2);
    fillRandom2D(A3);
    fillRandom2D(A4);
    fillRandom2D(A5);
    fillRandom2D(A6);

    return 0;
}
