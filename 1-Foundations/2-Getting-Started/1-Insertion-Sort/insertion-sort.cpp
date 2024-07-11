#include <iostream>

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[6] = {31, 41, 59, 26, 41, 58};

    int n = sizeof(arr) / sizeof(int);

    bool reverse = true;

    std::cout << "---- Start Sorting -----" << std::endl;
    if (!reverse) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;

            display_array(arr, n);
            std::cout << std::endl;
        }
    } else {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;

            display_array(arr, n);
            std::cout << std::endl;
        }
    }
    std::cout << "---- Finish Sorting -----"  << std::endl;
    
    std::cout << "End Result: ";
    display_array(arr, n);
    std::cout << std::endl;

    return 0;
}
