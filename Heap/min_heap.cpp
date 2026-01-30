#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    private:
        vector<int> min_heap;

        void heapifyUp(int index) {

            while(index > 0) {
                
                // find the parent
                int parent = (index - 1) / 2;

                // compare curr with parent
                // if smaller than parent then swap
                if(min_heap[index] < min_heap[parent]) {
                    swap(min_heap[index], min_heap[parent]);
                    index = parent;
                }
                // larger than parent
                // no heap property violation
                else break;
            }
        }

        void heapifyDown(int index) {
            int n = min_heap.size();

            while(true) {
                
                int smallest = index;
                int left = 2*index + 1;
                int right = 2*index + 2;
                
                // check if any child smaller than parent
                if(left < n && min_heap[left] < min_heap[smallest]) {
                    smallest = left;
                }
                if(right < n && min_heap[right] < min_heap[smallest]) {
                    smallest = right;
                }

                // check if smallest val change or not
                // i.e, changes it shows smallest elem exist in either on child
                if(smallest != index) {
                    swap(min_heap[smallest], min_heap[index]);
                    index = smallest;
                }
                else break;
            }
        }

    public:
        void insert(int val) {
            // push into min_heap
            min_heap.push_back(val);

            // heap property violates
            // call heapifyUp to resolve property violation
            heapifyUp(min_heap.size() - 1);
        }

        void build_min_heap(vector<int>& arr) {
            // copy array elements into min_heap            
            min_heap = arr;

            int n = min_heap.size();

            // start building heap from last internal node
            for(int i = (n - 2) / 2; i >= 0; i--) {
                heapifyDown(i);
            }
        }

        void updateKey(int index, int val) {
            // invalid index
            if(index < 0 || index >= min_heap.size()) return;

            // extract old val and replace with new val
            int oldVal = min_heap[index];
            min_heap[index] = val;

            // compare old val with new val to resolve heap property as per need
            if(oldVal < val) {
                heapifyDown(index);
            }
            else if(oldVal > val) {
                heapifyUp(index);
            }
        }

        bool is_min_heap() {
            int n = min_heap.size();
            
            // iterate over internal nodes
            // verify heap property
            for(int i = 0; i <= (n - 2) / 2; i++) {
                int left = 2*i + 1;
                int right = 2*i + 2;
                
                // check if both left and right is in correct order
                if(left < n && min_heap[left] < min_heap[i]) return false;
                if(right < n && min_heap[right] < min_heap[i]) return false;
            }
            return true;
        }

        void deleteMin() {
            // if min_heap empty
            if(min_heap.empty()) return;

            // replace root with last el
            min_heap[0] = min_heap.back();

            // remove last elem from heap - as it is already copyed to root
            min_heap.pop_back();

            // heap property violates
            // call heapifyDown to resolve property violation
            if(!min_heap.empty()) heapifyDown(0);
        }

        int getMin() {
            if(min_heap.empty()) return -1;
            return min_heap[0];
        }

        void print_heap() {
            for(int el: min_heap) {
                cout << el << " ";
            }
            cout << endl;
        }
};

int main() {

    MinHeap hp;

    // hp.insert(5);
    // hp.insert(10);
    // hp.insert(15);
    // hp.insert(20);
    // hp.insert(25);
    vector<int> arr = {40, 25, 10, 20, 15, 5, 30, 50, 35};
    hp.build_min_heap(arr);
    cout << "Is Min heap: " << hp.is_min_heap() << endl;
    hp.print_heap();
    hp.updateKey(5, 70);
    hp.print_heap();
    hp.deleteMin();
    hp.print_heap();


}