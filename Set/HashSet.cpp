#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int key): key(key), next(nullptr) {};
};

class HashSet {
    private:
        int capacity;
        Node** table;

        int hashFunction(int key) {
            return key % capacity; 
        }
    
    public:
        HashSet(int cap = 10) {
            this->capacity = cap;
            table = new Node*[capacity];

            // initialize all indices
            for(int i = 0; i < capacity; i++) {
                table[i] = nullptr;
            }
        }

        void add(int key) {
            
            // retrieve the bucket index
            int index = hashFunction(key);

            // retrieve the bucket head
            Node* curr = table[index];

            // check key already exist or not
            while(curr) {
                // find key
                if(curr->key == key) {
                    cout << "Key = " << key << " already exist" << endl;
                    return;
                }  
                
                // iterate
                curr = curr->next;
            }

            // add new key at beg
            Node* newNode = new Node(key);
            newNode->next = table[index];

            // update the new head
            table[index] = newNode;
        }

        bool contains(int key) {
            
            // retrieve bucket index
            int index = hashFunction(key);

            // retrieve bucket head
            Node* curr = table[index];
            
            // Check exist or not
            while(curr) {
                // find key
                if(curr->key == key) return true;
                
                // iterate
                curr = curr->next;
            }
            return false;
        }

        void remove(int key) {
            
            // retrieve bucket index
            int index = hashFunction(key);

            // retrieve bucket head
            Node* curr = table[index];
            Node* prev = nullptr;

            // check exist or not
            while(curr) {
                // find key
                if(curr->key == key) {
                    // if head
                    if(!prev) {
                        table[index] = curr->next;

                    }
                    else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    return;
                }

                // iterate
                prev = curr;
                curr = curr->next;
            }
        }

        bool isEmpty() {
            for(int i = 0; i < capacity; i++) {
                if(table[i]) return false;
            }
            return true;
        }

        void display() {

            // iterate over the bucket indices
            for(int i = 0; i < capacity; i++) {

                // define bucket head
                Node* curr = table[i];
                
                cout << "Index " << i << ": "; 

                // Iterate over each bucket index
                while(curr) {
                    cout << curr->key << " ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }
};

int main() {

    HashSet st(5);

    st.add(10);
    st.add(20);
    st.add(15);   // collision example
    st.add(10);   // duplicate ignored

    st.display();

    cout << st.contains(20) << endl; // 1
    cout << st.contains(99) << endl; // 0

    st.remove(10);
    st.display();

}