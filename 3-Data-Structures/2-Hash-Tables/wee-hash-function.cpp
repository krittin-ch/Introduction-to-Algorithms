#include <bits/stdc++.h>

using namespace std;

void random_bits(string &a, int w) {
    for (int i = 0; i < w; i++) {
        a += to_string(rand() % 2);
    }
}

// void chop()

string swap_bits(const string &x, int w) {
    string result = x; 

    for (char &c : result) {
        c = (c >> (w/2)) | (c << (w/2));
    }
    
    return result;
}


int main() {
    srand(time(0));
    string a = "";
    string b = "";

    int w = 32;
    random_bits(a, w-1);
    a += "1";

    random_bits(b, w);

    string k = "111111111";

    string n = swap_bits(k, 3);

    cout << n << endl;

    cout << stoul(a, nullptr, 2);
    return 0;
}