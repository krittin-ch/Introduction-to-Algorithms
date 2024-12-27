#include <bits/stdc++.h>

using namespace std;

int hashNumber(int key, int a, int b, int p, int m) {
    // a and b are arbitrary integer
    // p is a prime number and p > m
    // m is the size of domain U : the number of slots for hashing outputs
    return ((a * key + b) % p) % m;
}

int main() {
    int p = 17;
    int m = 6;
    int a = 3;
    int b = 4;

    int hs_1 = hashNumber(8, a, b, p, m);

    cout << "Hashing Output : " << hs_1 << endl;
    
    for (int i = 0; i < 20; i++) {
        cout << "Hashing Output : " << hashNumber(i, a, b, p, m) << endl;
    }
    
    return 0;
}