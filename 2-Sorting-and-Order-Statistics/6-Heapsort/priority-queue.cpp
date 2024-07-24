#include <bits/stdc++.h>
#include <optional>

using namespace std;

void printTree(vector<int> vec) {
    int n = vec.size();
    if (n == 0) return;

    int h = log2(n) + 1;
    int max_width = pow(2, h - 1);

    int count = 0;
    for (int i = 0; i < h; i++) {
        int nodes = pow(2, i);
        int partition = max_width / nodes;

        for (int k = 0; k < partition / 2; k++) {
            cout << " ";
        }

        for (int j = 0; j < nodes && count < n; j++) {
            cout << vec[count];
            count++;

            for (int k = 0; k < partition; k++) {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void displayArray(vector<int> vec)
{
  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << " ";
  std::cout << "\n\n";
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap_elements(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeapify(vector<int> &vec, int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap_size && vec[l] > vec[largest]) {
        largest = l;
    }

    if (r < heap_size && vec[r] > vec[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap_elements(&vec[i], &vec[largest]);
        maxHeapify(vec, largest, heap_size);
    }
}

void buildMaxHeap(vector<int> &vec) {
    int heap_size = vec.size();
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        maxHeapify(vec, i, heap_size);
    }
}

int maxHeapMaximum(vector<int> vec) {
    if (vec.size() < 1) {
        throw runtime_error("Heap Underflow");
    }
    return vec[0];
}


int maxHeapExtractionMax(vector<int> &vec) {    
    // vector<int> &vec allows to reference to the original arrays (heap)
    // vector<int> vec  copys the original array and modify - which is not prefered
    int heap_size = vec.size();
    int max = maxHeapMaximum(vec);
    vec[0] = vec[heap_size - 1];
    vec.pop_back(); // Remove the last element
    heap_size--;
    maxHeapify(vec, 0, heap_size);
    return max;
}

void maxHeapIncreaseKey(vector<int>& vec, int index, int key) {
    if (index >= vec.size()) {
        throw runtime_error("Index is out of bounds");
    }
    if (key < vec[index]) {
        throw runtime_error("New Key is Smaller than Current Key");
    }
    vec[index] = key;
    
    // Swap the input key (located at the last index) with its parent until it reaches the correct position
    while (index > 0 && vec[parent(index)] < vec[index]) {
        swap_elements(&vec[parent(index)], &vec[index]);
        index = parent(index);
    }
}

// Function to insert a new key into the max heap
void maxHeapInsert(vector<int>& vec, int key, int n) {
    if (vec.size() >= n) {
        throw runtime_error("Heap Overflow");
    }
    vec.push_back(INT_MIN); // Add a new element with the smallest possible value
    maxHeapIncreaseKey(vec, vec.size() - 1, key);
}


int main() {
    // vector<int> vec = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 28};
    vector<int> vec = {10, 20, 30, 25, 26, 27, 1, 2, 3, 4};
    cout << "Original Heap : " << endl;
    printTree(vec); 
    // displayArray(vec);

    cout << "Max Heapified Sort : " << endl;
    buildMaxHeap(vec);
    printTree(vec);
    // displayArray(vec);

    for (int i = 0; i < vec.size(); i++) {
        cout << maxHeapExtractionMax(vec) << " ";
    }
    cout << endl;

    // printTree(vec);

    int n = 100;

    vector<int> newHeap = {10, 20, 30};
    cout << "Inserting Keys : " << endl;
    buildMaxHeap(newHeap);
    maxHeapInsert(newHeap, 5, n);
    maxHeapInsert(newHeap, 26, n);
    maxHeapInsert(newHeap, 27, n);
    maxHeapInsert(newHeap, 1, n);
    maxHeapInsert(newHeap, 2, n);
 
    printTree(newHeap);
    // displayArray(newHeap);

    return 0;
}