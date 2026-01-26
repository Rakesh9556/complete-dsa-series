#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

    void resize() {
        // define the new capacity
        int new_capacity = capacity * 2;

        // define new array with new capacity
        int* new_arr = new int[new_capacity];

        // copy old elements into new array
        for(int i = 0; i <= top; i++) {
            new_arr[i] = arr[i];
        }

        // delete the old array
        delete[] arr;
        
        // update the arr to new array and capacity to new capacity
        arr = new_arr;
        capacity = new_capacity;

    }

    public:
        Stack(int capacity) {
            arr = new int[capacity];
            top = -1;
            this->capacity = capacity;
        }

        void push(int val) {
            // check stack is full or not
            if(top == capacity - 1) {
                resize();
                // cout << "Stack overflow" << endl;
                // return;
            }
            top++;
            arr[top] = val;
        }

        void pop() {
            // check stack is empty or not
            if(top == -1) {
                cout << "Stack underflow" << endl;
                return;
            }
            top--;
        }

        int peek() {
            // check stack is empty or not
            if(top == -1) {
                cout << "Stack is empty" << endl;
            }
            return arr[top];
        }

        int size() {
            return top + 1;
        }

        bool isEmpty() {
            return top == -1;
        }

        ~Stack() {
            delete[] arr;
        }
};

int main() {

    int n;
    cin >> n;

    Stack st(n);
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