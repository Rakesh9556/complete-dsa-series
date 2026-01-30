#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class MaxHeap {
    private:
        vector<int> max_heap;

        void heapifyUp(int pos) {
            
            while(pos != 0) {

                // find parent
                int parent = (pos - 1) / 2;

                // compare inserted elem with parent

                // elem is greater than parent
                if(max_heap[pos] > max_heap[parent]) {

                    // swap both
                    swap(max_heap[pos], max_heap[parent]);

                    // update pos to parent
                    pos = parent;
                }

                // elem is smalle
                else break;
            }

        }

        void heapifyDown(int root) {
            
            int n = max_heap.size();
            
            while(true) {

                // find the larger elem
                int largest = root;
                int left = 2 * root + 1;
                int right = 2 * root + 2;

                // if left is larger
                if(left < n && max_heap[left] > max_heap[largest]) {
                    largest = left;
                }

                // if right is larger
                if(right < n && max_heap[right] > max_heap[largest]) {
                    largest = right;
                }

                // if one child is larger
                // if root is already the largest, max_heap property is satisfied
                if(root != largest) {
                    swap(max_heap[root], max_heap[largest]);
                    root = largest;
                }
                else break; // means when root is the largest
            }

        }
    
    public:
        void insert(int val) {
            // insert elem
            max_heap.push_back(val);

            // max_heapify the max_heap as in every insert max_heap structure violates
            heapifyUp(max_heap.size() - 1);
        }

        void deleteMax() {
            // if empty
            if(max_heap.empty()) return;

            // safe delete the max elem in max_heap (root) - replace root with last elem (maintaining cbt)
            max_heap[0] = max_heap.back();

            // delete the last elem - as it already in the root
            max_heap.pop_back();

            // apply max_heapifyDown on the max_heap as max_heap property is violated
            // i.e, root elem order is not correct
            heapifyDown(0);
        }

        int getMax() {
            if(max_heap.empty()) return -1;
            return max_heap[0];
        }

        void build_max_heap(vector<int> &arr) {
            max_heap = arr;

            int n = max_heap.size();

            // build subtrees from last internal node
            for(int i = (n / 2) - 1; i >= 0; i--) {
                heapifyDown(i);
            }
        }

        void updateKey(int index, int val) {
            // invalid index
            if(index < 0 || index >= max_heap.size()) return;

            // update new val in index
            int oldVal = max_heap[index];
            max_heap[index] = val;
            
            // compare the new val with existing val and restore max_heap property
            if(oldVal < val) {
                heapifyUp(index);
            }
            else if(oldVal > val) {
                heapifyDown(index);
            }
        }

        bool is_max_heap() {
            int n = max_heap.size();

            // iterate over internal nodes
            // check it satisfies max_heap property or not
            for(int i = 0; i <= (n-2) / 2; i++) {
                
                // find left and right
                int left = 2*i + 1;
                int right = 2*i + 2;

                // check max_heap property satisfies or not
                if(left < n && max_heap[i] < max_heap[left]) return false;
                if(right < n && max_heap[i] < max_heap[right]) return false;
            }
            return true;
        }

        void print_heap() {
            for(int el: max_heap) {
                cout << el << " ";
            }
            cout << endl;
        }
};

int main() {

    MaxHeap hp;

    // hp.insert(5);
    // hp.insert(10);
    // hp.insert(15);
    // hp.insert(20);
    // hp.insert(25);
    vector<int> arr = {40, 25, 10, 20, 15, 5, 30, 50, 35};
    hp.build_max_heap(arr);
    cout << "Is max_heap: " << hp.is_max_heap() << endl;
    hp.print_heap();
    hp.updateKey(5, 70);
    hp.print_heap();
    hp.deleteMax();
    hp.print_heap();


}