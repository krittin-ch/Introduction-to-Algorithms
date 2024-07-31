#include <bits/stdc++.h>
#include <optional>

using namespace std;

class MaxHeap {
    private :
        vector<int> heap;

        int parent(int i) {
            return (i - 1) / 2;
        }

        int left(int i) {
            return 2 * i + 1;
        }

        int right(int i) {
            return 2 * i + 2;
        }

        void maxHeapify(int i) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            int heap_size = heap.size();

            if (l < heap_size && heap[l] > heap[largest]) {
                largest = l;
            }

            if (r < heap_size && heap[r] > heap[largest]) {
                largest = r;
            }

            if (largest != i) {
                swap(heap[largest], heap[i]);
                maxHeapify(largest);
            }
        }

        void buildMaxHeap() {
            int heap_size = heap.size();
            for (int i = heap_size / 2 - 1; i >= 0; i--) {
                maxHeapify(i);
            }
        }

    public :
        MaxHeap(const vector<int> vec) : heap(vec) {
                buildMaxHeap();
        }

        /*
        OR 
        MaxHeap(const vector<int> vec) {
            heap = vec;
            buildMaxHeap();
        }
        */

        int maxHeapMaximum() {
            if (heap.size() < 1) {
                throw runtime_error("Heap Underflow");
            }

            return heap[0];
        }
        
        int maxHeapExtractionMax() {
            int heap_size = heap.size();
            int max = maxHeapMaximum();
            heap[0] = heap[heap_size - 1];
            heap.pop_back();
            maxHeapify(0);

            return max;
        }

        void maxHeapIncreaseKey(int index, int key) {
            if (index >= heap.size()) {
                throw runtime_error("Index is out of bounds");
            }
            if (key < heap[index]) {
                throw runtime_error("New Key is Smaller than Current Key");
            }

            heap[index] = key;

            while (index > 0 && heap[parent(index)] < heap[index]) {
                swap(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }

        void maxHeapInsert(int key) {
            heap.push_back(INT_MIN);
            maxHeapIncreaseKey(heap.size() - 1, key);
        }

        int searchMaxHeap(int key) {
            for(int i = 0; i < heap.size(); i++) {
                if (heap[i] == key) {
                    return i;
                }
            }
            throw runtime_error("The Heap Does Not Contain the Key");
        }

        void maxHeapDelete(int key) {
            int index = searchMaxHeap(key);
            swap(heap[index], heap[heap.size() - 1]);
            heap.pop_back();
            maxHeapify(index);
        }

        void printHeap() {
            int n = heap.size();
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
                    cout << heap[count];
                    count++;

                    for (int k = 0; k < partition; k++) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        void displayArray() {
            for (int i = 0; i < heap.size(); ++i)
                cout << heap[i] << " ";
            cout << "\n\n";
        }
};

int main() {
    vector<int> vec = {1, 2, 3, 4};

    MaxHeap heap1(vec);

    cout << "Max-Heap : " << endl;
    heap1.printHeap();
    
    for (int i = 0; i < 6; i++) {
        heap1.maxHeapInsert(i*-1);
    }

    cout << "Max-Heap : " << endl;
    heap1.printHeap();

    heap1.maxHeapDelete(4);
    cout << "Max-Heap : " << endl;
    heap1.printHeap();

    return 0;
}