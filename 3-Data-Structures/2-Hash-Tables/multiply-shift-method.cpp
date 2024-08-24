#include <bits/stdc++.h>

using namespace std;

class HashTable {
    private:
        static const int TABLE_SIZE = 16;
        static const int w = 31;
        static const int l = 4;
        static const unsigned int a = 2654435769U;

        int table[TABLE_SIZE];

        int hash(int key) {
            int hash_value = (key * a) % (1 << w); // (k * a) mod 2^w
            return hash_value >> (w - l);           // Right shift to get the hash index
        }

    public:
        HashTable() {
            for(int i = 0; i < TABLE_SIZE; ++i) {
                table[i] = -1;
            }
        }

        void insert(int key, int val) {
            int idx = hash(key);

            while (table[idx] != -1) {
                idx = (idx + 1) % TABLE_SIZE;
            }
            table[idx] = key;  // Store the key, not the value
        }

        int search(int key) {
            int index = hash(key);
            int start_index = index;

            while (table[index] != -1) {
                if (table[index] == key) {
                    return key;  // Return the key, not the value
                }

                index = (index + 1) % TABLE_SIZE;
                if (index == start_index) {
                    break;
                }
            }
            return -1;
        }
};

int main() {
    HashTable ht;
    ht.insert(5, 0);
    ht.insert(25, 0);
    ht.insert(15, 0);

    int result = ht.search(25);
    if (result != -1) {
        cout << "Key found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}