#include <iostream>
using namespace std;
#define MAX_SIZE 10

class Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;

    public:
        Queue() {
            front = rear = -1;
        }

        void enqueue(int val) {
            // check if max size is reached
            if((rear + 1) % MAX_SIZE == front) {
                cout << "Maximum size reached" << endl;
                return;
            }

            // check if first elem or not
            if(front == -1) {
                front = 0;
            }

            // increment the rear and add elem
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = val;
        }

        void dequeue() {

            // check if queue is empty or not
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            // onl one element
            if(front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }

        void display() {
            
            // check if empty or not
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            for(int i = front; i <= rear; (i + 1) % MAX_SIZE) {
                cout << arr[i] << " ";
            }
        }
};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);
    q.display();
}