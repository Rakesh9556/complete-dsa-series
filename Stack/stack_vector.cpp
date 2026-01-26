#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

    public:
        void push(int val) {
            v.push_back(val);
        }

        void pop() {
            v.pop_back();
        }

        int peek() {
            // check if vector is empty or not
            if(v.empty()) return -1;
            return v.back();
        }

        int size() {
            return v.size();
        }

        bool isEmpty() {
            return v.empty();
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