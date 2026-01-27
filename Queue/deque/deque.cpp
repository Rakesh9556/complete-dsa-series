#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int cnt;

    public:
        Deque() {
            front = -1;
            rear = -1;
            cnt = 0;
        }

        void insertRear(int val) {
            // check if deque is full or not
            if(front == (rear + 1) % MAX_SIZE) {
                cout << "Deque overflow" << endl;
                return;
            }

            // check if first elem
            if(front == -1) {
                front = rear = 0;
            } 
            else {
                rear = (rear + 1) % MAX_SIZE;
            }
            
            /* Alternate
            else if (rear == MAX_SIZE - 1) {
                rear = 0;
            }
            else {
                rear++;
            }
            */
            
            // Insert elem
            arr[rear] = val;
            cnt++;
        }

        void insertFront(int val) {
            // check if deque is full or not
            if(front == (rear + 1) % MAX_SIZE) {
                cout << "Deque overflow" << endl;
                return;
            }
            
            // check if first elem
            if(front == -1) {
                front = rear = 0;
            }
            else {
                front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            }

            /* Alterante code
            else if(front == 0){
                front = MAX_SIZE - 1;
            }
            else {
                front--;
            }
            */

            // insert elem
            arr[front] = val;
            cnt++;
        }

        void deleteRear() {

            // check deque is empty or not
            if(front == -1) {
                cout << "Deque underflow" << endl;
                return;
            }
            
            // check if only one elem
            if(front == rear) {
                front = rear = -1;
            }
            else {
                rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
            }
            cnt --;

            /*
            else if(rear == 0) {
                rear = MAX_SIZE - 1;
            }
            else {
                rear--;
            }
            */

        }

        void deleteFront() {

            // check if deque is empty or not
            if(front == -1) {
                cout << "Deque underflow" << endl;
                return;
            }

            // check if only one elem
            if(front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % MAX_SIZE;
            }
            cnt--;
            /*
            else if(front == MAX_SIZE - 1) {
                front = 0;
            }
            else {
                front++;
            }
            */
        }

        void display() {

            if(front == -1) {
                cout << "Empty deque" << endl;
                return;
            }

            int i = front;
            while(true) {
                cout << arr[i] << " ";
                if(i == rear) break;
                i = (i + 1) % MAX_SIZE;
            }
            cout << endl;
        }

        int size() {
            return cnt;
        }
};

int main() {

    Deque dq;
    dq.deleteFront();
    dq.insertFront(5);
    dq.display();
    dq.deleteRear();
    dq.display();
    dq.insertRear(10);
    dq.insertFront(5);
    dq.display();
    cout << dq.size();

}