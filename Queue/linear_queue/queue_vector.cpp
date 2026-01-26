#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> v;
    int front;
    int rear;

    public:
        Queue () {
            front = rear = -1;
        }

        void enqueue(int val) {
            if(front == -1) {
                front = 0;
            }
            rear++;
            v.push_back(val);
        }

        void dequeue() {

            // check if queue is empty or not
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            front++;

            if(front > rear) {
                front = rear = -1;
                v.clear();
            }
        }
};


int main() {
    
    Queue q;
    q.dequeue();
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.dequeue();
    q.enqueue(30);
}