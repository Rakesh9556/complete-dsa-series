#include <iostream>
#define MAX_SIZE 5
using namespace std;


class Queue {
    int arr[MAX_SIZE];
    int rear;
    int front;

    public:
        Queue() {
            rear = front = -1;
        }

        void enqueue(int val) {

            // check if size exceeds or not
            if(rear == MAX_SIZE - 1) {
                cout << "Queue max size reached" << endl;
                return;
            }

            // check if it is first element or not
            if(front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = val;
        }

        void dequeue() {
            
            // check if queue is empty or not
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            // remove element from front (increment front by 1)
            front++;

            // check if front exceeds rear or not
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
            return rear == MAX_SIZE - 1;
        }

};

int main() {

    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.dequeue();
    q.enqueue(30);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
}