#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;

    public:
        Queue(int size) {
            arr = new int[size];
            front = rear = -1;
            this->size = size;
        }

        void enqueue(int val) {

            // check if max size reaached or not
            if(rear == size -1) {
                cout << "Queue is full" << endl;
                return;       
            }

            // check if it is the first elem or not
            if(front == -1) {
                front = 0;
            }

            // increment rear and insert elem
            rear++;
            arr[front] = val;

        }

        void dequeue() {
            
            // check if queue is empty or not
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            // remove element (increment front by 1 to remove)
            front++;

            // check if queue becomes empty again or not
            if(front > rear) {
                front = rear = -1;
            }
        }

        int peek() {
            return arr[front];
        }

        bool isEmpty() {
            return front == -1;
        }

        bool isFull() {
            return rear == size - 1;
        }
};

int main() {
    
    int n;
    cin >> n;

    Queue q(n);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25); // Output: Queue is full
    q.dequeue();
    q.enqueue(30); // Output: Queue is full
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;

}