#include <iostream>

int main() {
    int searchKey = 410;
    int arr[6] = {31, 41, 59, 26, 41, 58};
    int n = sizeof(arr)/sizeof(int);

    for (int i = 0; i < n; i++) {
        if (searchKey == arr[i]) {
            std::cout << searchKey << " found at idx: " << i;
            std::cout << std::endl;
            // return 0;
        }
    }

    std::cout << "NIL not found idx";
    return 0;
}
