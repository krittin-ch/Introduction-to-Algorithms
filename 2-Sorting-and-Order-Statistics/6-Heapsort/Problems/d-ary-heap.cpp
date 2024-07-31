#include <bits/stdc++.h>

using namespace std;

class DAryHeap {
    private :
        vector<int> heap;
        int dAry;   // If dAry is 2, then it is a binary heap.

        int heapDepth() {
            return log_a_to_base_b(heap.size() - 1, dAry) + 1;
        }



        int parent(int i) {
            return (i - 1) / dAry;
        }

        int firstChild(int i) {
            return dAry * i + 1;
        }

        int lastChild(int i) {
            return dAry * (i + 1);
        }

        void maxHeapify(int i, int heap_size) {
            int fChild = firstChild(i);
            int lChild = lastChild(i);
            
            while (fChild < heap_size && fChild <= lChild) {
                if (heap[i] < heap[fChild]) {
                    swap(heap[i], heap[fChild]);
                    maxHeapify(fChild, heap_size);
                }
                fChild++;
            }
        }


        int log_a_to_base_b(int a, int b) {
            return ceil(log2(a) / log2(b));
        }
    
    public : 
        void buildMaxHeap() {
            int heap_size = heap.size();
            for (int i = parent(heap.size()); i >= 0; i--) {
                maxHeapify(i, heap_size);
            }
        }

        DAryHeap(const vector<int> arr, const int d_Ary) : heap(arr), dAry(d_Ary) {
            buildMaxHeap();
        }

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
            maxHeapify(0, heap_size);

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

            while(index > 0 &&  heap[parent(index)] < heap[index]) {
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
            
            maxHeapify(index, heap.size());
        }

        void constructSortedArray() {
            int heap_size = heap.size();

            for (int i = heap.size() - 1; i > 0; i--) {
                swap(heap[0], heap[i]);
                heap_size--;
                maxHeapify(0, heap_size);
            } 
        }

        void printHeap() {
            int i = 0;
            for (int depth = 0; depth < heapDepth(); depth++) {
                int num = pow(dAry, depth);
                while (num != 0 && i < heap.size()) {
                    cout << heap[i] << " ";
                    if ((num + dAry - 1) % dAry == 0) {
                        // cout << "  " << num << "  "; 
                        cout << " | ";
                    }
                    i++;
                    num--;
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
    // vector<int> vec = {9, 16, 3, 2, 4, 8, 5, 14, 12, 17, 42, 25, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int dAry = 5;

    DAryHeap heap1(vec, dAry);

    cout << "Initial heap : " << endl;
    heap1.printHeap();

    cout << "Extracting maximum element from heap : " << endl;
    
    int max_num = heap1.maxHeapExtractionMax();
    cout << "MAX : " << max_num << endl;

    cout << "Heap after extracting max : " << endl;
    heap1.printHeap();

    cout << "Constructing sorted array : " << endl;
    heap1.constructSortedArray();
    cout << "Heap after constructing sorted array : " << endl;
    heap1.printHeap();

    cout << "Displaying array representation of heap (sorted array) : " << endl;
    heap1.displayArray();

    cout << "Rebuilding max heap : " << endl;
    heap1.buildMaxHeap();
    cout << "Heap after rebuilding max heap : " << endl;
    heap1.printHeap();

    cout << "Final array representation of heap : " << endl;
    heap1.displayArray();
    cout << "Final heap state : " << endl;
    heap1.printHeap();

    return 0;
}
