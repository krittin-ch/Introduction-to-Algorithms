#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

class DirectAddressTable {
    private :
        vector<int> T;
        int capacity;

    public :
        DirectAddressTable(int maxKey) {
            capacity = maxKey + 1;
            T.resize(capacity, MAX);
        };

        void directAddressInsert(int key, int val) {
            if (key > capacity) {
                cout << "key exceeds capacity";
                return;
            }

            T[key] = val;
        }

        int directAddressSearch(int key) {
            if (T[key] != MAX) {  // Check if the key exists
                return T[key];
            }
            return -1;
        }

        void directAddressDelete(int key) {
            T[key] = MAX;
        }

        void display() {
            for (int i = 0; i < capacity; i++) {
                if (T[i] != MAX) {
                    cout << "key : " << i << " val : " << T[i] << endl;
                }
            }
            cout << endl;
        }
};

int main() {
    DirectAddressTable dat(10);

    dat.directAddressInsert(2, 50);  
    dat.directAddressInsert(5, 100);  
    dat.directAddressInsert(10, 200);

    cout << "Search key 2: " << dat.directAddressSearch(2) << endl;
    cout << "Search key 3: " << dat.directAddressSearch(3) << endl;  

    dat.directAddressDelete(5);
    cout << "Search key 5 after deletion: " << dat.directAddressSearch(5) << endl;  

    dat.display(); 

    return 0;
}