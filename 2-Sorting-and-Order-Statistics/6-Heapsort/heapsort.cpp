#include <iostream>
#include <vector>
#include <cmath>

void displayArray(std::vector<int> &vec)
{
  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << " ";
  std::cout << "\n\n";
}

void printTree(std::vector<int> vec) {
    int h = std::log2(vec.size()) + 1;
    int max_width = std::pow(2, h);
    int count = 0;
    for (int i = 0; i < h; i++) {
        int nodes = std::pow(2, i);
        int partition = max_width/nodes;
        for (int j = 0; j < nodes; j++) {
            if (count < vec.size()) {
                for (int k = 0; k <= partition; k++) {
                    std::cout << " ";
                }
                std::cout << vec[count];
                count++;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void swap_elements(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void maxHeapify(std::vector<int> &vec, int i, int heap_size) {
    /*
             root
           /     \
          /       \
        left    right
       
        maxHeapify check only the root and its childrean
        Not all successive nodes
    */

    int l = left(i);
    int r = right(i);
    int largest = i;
    // displayArray(vec);

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

void minHeapify(std::vector<int> &vec, int i, int heap_size) {
    /*
             root
           /     \
          /       \
        left    right
       
        minHeapify check only the root and its childrean
        Not all successive nodes
    */

    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && vec[l] < vec[smallest]) {
        smallest = l;
    }
    if (r < heap_size && vec[r] < vec[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap_elements(&vec[i], &vec[smallest]);
    }
    minHeapify(vec, smallest, heap_size);
}

void buildHeap(std::vector<int> &vec, bool min_to_max) {
    /*
        The `buildHeap` function satisfies the loop invariant at each iteration
        by moving the largest values from the leaves up to the upper nodes. 
        
        The recursive calls in the maxHeapify function then move smaller 
        values from the upper nodes down to the lower nodes.
    */

    int heap_size = vec.size();

    if (min_to_max) {
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            maxHeapify(vec, i, heap_size);
        }
    } else {
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            minHeapify(vec, i, heap_size);
        }
    }
}

void heapSort(std::vector<int> &vec, bool min_to_max) {
    buildHeap(vec, min_to_max);
    int heap_size = vec.size();
   
    if (min_to_max) {
        for (int i = vec.size() - 1; i > 0; --i) {
        swap_elements(&vec[0], &vec[i]);
        --heap_size;                  
        maxHeapify(vec, 0, heap_size);
        }
    } else {
        for (int i = vec.size() - 1; i > 0; --i) {
        swap_elements(&vec[0], &vec[i]);
        --heap_size;                  
        minHeapify(vec, 0, heap_size);
        }
    }
}

int main() {
    std::vector<int> vec = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 28};

    bool min_to_max = true;
   
    std::cout << "Original Array" << std::endl;
    displayArray(vec);
    printTree(vec);
   
    buildHeap(vec, min_to_max);
   
    std::cout << "Heapified Array" << std::endl;
    displayArray(vec);
    printTree(vec);
   
    heapSort(vec, min_to_max);
   
    std::cout << "Sorted Array" << std::endl;
    displayArray(vec);

    return 0;
}