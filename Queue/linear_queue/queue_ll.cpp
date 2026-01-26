#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

    public:
        Node(int data) {
            this->data = data;
            next = nullptr;
        }

        friend class Queue; // allow this class acess to Queue class
};

class Queue {
    Node* front;
    Node* rear;

    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        void enqueue(int data) {
            
            Node* newNode = new Node(data);

            // check if queue is empty or not
            if(rear == nullptr) {
                front = rear = newNode;
                return;
            }

            // if not empty
            rear->next  = newNode;
            rear = rear->next;
        }

        void dequeue() {
            
            // check if queue is empty or not
            if(front == nullptr) {
                cout << "Queue is empty" << endl;
                return;
            }

            // if not empty
            Node* temp = front;
            front = front->next;

            // check if front is empty or not
            if(front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }

        int peek () {
            // check if queue is empty or not
            if(front == nullptr) return -1;
            return front->data;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void display() {
            Node* temp = front;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
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
    cout << q.isEmpty() << endl;
    q.display();
}