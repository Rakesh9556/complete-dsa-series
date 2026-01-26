#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};


class Stack {
    Node* top;
    int n;

    public:
        Stack() {
            top = nullptr;
            n = 0;
        }

        void push(int val) {
            Node* node = new Node(val);
            node->next = top;
            top = node;
            n++;
        }

        void pop() {
            if(top == nullptr) {
                cout << "Stack underflow" << endl;
                return;
            }

            Node* delNode = top;
            top = top->next;
            delete delNode;
            n--;
        }

        int peek() {
            if(top == nullptr) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }

        int size() {
            return n;
        }

        bool isEmpty() {
            return top == nullptr;
        }
};

int main() {
    
    Stack st;
    cout << st.size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout << st.size() << endl;
    st.push(60);
    st.push(70);
    st.pop();
    cout << st.peek() << endl;
    cout << st.size() << endl;
    cout << st.isEmpty() << endl;
}