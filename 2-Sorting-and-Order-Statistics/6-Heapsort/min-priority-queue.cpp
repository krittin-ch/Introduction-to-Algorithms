#include <bits/stdc++.h>

using namespace std;

class MinHeap {
    private:
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

        void minHeapify(int i) {
            int l = left(i);
            int r = right(r);
            int smallest = i;

            if (l < heap.size() && heap[l] < heap[smallest]) {
                smallest = l;
            }

            if (r < heap.size() && heap[r] < heap[smallest]) {
                smallest = r;
            }

            if (smallest != i) {
                swap(heap[smallest], heap[i]);
                minHeapify(smallest);
            }
        }

        void buildMinHeapify() {
            int heap_size = heap.size();
            for (int i = heap_size / 2 - 1; i >= 0; i--) {
                minHeapify(i);
            }
        }

    public:
        MinHeap(const vector<int> vec) {
            heap = vec;
            buildMinHeapify();
        }

        /*
        OR
        MinHeap(const vector<int> vec) : heap(vec) {
            buildMinHeapify()
        }
        */ 

        int minHeapMinimum() {
            if (heap.size() < 1) {
                throw runtime_error("Heap Underflow");
            }
            
            return heap[0];
        }

        int minHeapExtractionMin() {
            int heap_size = heap.size();
            int min = minHeapMinimum();
            heap[0] = heap[heap_size - 1];
            heap.pop_back();
            minHeapify(0);
            
            return min;
        }

        void minHeapDecreaseKey(int index, int key) {
            if (index >= heap.size()) {
                throw runtime_error("Index is out of bounds");
            }
            if (key > heap[index]) {
                throw runtime_error("New Key is Larger than Current Key");
            }

            heap[index] = key;

            while (index > 0 && heap[parent(index)] > heap[index]) {
                swap(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }

        void minHeapInsert(int key) {
            heap.push_back(INT_MAX);
            minHeapDecreaseKey(heap.size() -  1, key);
        }

        int searchMinHeap(int key) {
            for(int i = 0; i < heap.size(); i++) {
                if (heap[i] == key) {
                    return i;
                }
            }
            throw runtime_error("The Heap Does Not Contain the Key");
        }

        void minHeapDelete(int key) {
            int index = searchMinHeap(key);
            swap(heap[index], heap[heap.size() - 1]);
            heap.pop_back();
            minHeapify(index);
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
    vector<int> vec = {1, 2, 3, 4, 5};

    MinHeap heap1(vec);

    cout << "Min-Heap : " << endl;
    heap1.printHeap();
    
    for (int i = 0; i < 6; i++) {
        heap1.minHeapInsert(i*10);
    }

    cout << "Min-Heap : " << endl;
    heap1.printHeap();

    heap1.minHeapDelete(0);
    cout << "Min-Heap : " << endl;
    heap1.printHeap();
    return 0;
}