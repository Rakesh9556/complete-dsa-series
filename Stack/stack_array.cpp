#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Stack {
    int arr[MAX_SIZE];
    int top;

    public:
        Stack() {
            top = -1;
        }

        void push(int val) {
            if(top == MAX_SIZE) {
                cout << "Stack Overflow! Cannot push more elements" << endl;
                return;
            }
            top++;
            arr[top] = val;
        }

        void pop() {
            if(top == -1) {
                cout << "Stack Underflow! Cannot remove elements" << endl;
                return;
            }
            top--;
        }

        int peek() {
            if(top == -1) {
                cout << "Stack is empty! Value not found";
                return -1;
            }
            cout << endl;
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

    Stack st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    cout << st.size();
    cout << st.peek();
    st.push(40);
    st.push(30);
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    cout << st.size();
    cout << st.peek();
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.size();
    cout << st.peek();


    return 0;
}