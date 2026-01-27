#include <iostream>
using namespace std;

struct Node {
    int key, val;
    Node* next;

    Node(int k, int v) : key(k), val(v), next(nullptr) {};
};

class HashMap {
    private:
        int capacity;
        Node** table;

        int hashFunction(int key) {
            return key % capacity;
        }

    public:
        HashMap(int cap = 10) {
            this->capacity = cap;
            table = new Node*[capacity];
            for(int i = 0; i < capacity; i++) {
                table[i] = nullptr;
            }
        }

        void put(int key, int val) {
            // hash the key and convert into bucket index
            int index = hashFunction(key);

            // retrieve the bucket head
            // table[index] -> represents head of the linked list in specific bucket index
            Node* curr = table[index];

            // check if linked list empty or not
            // If empty, i.e, no existing key / no collision
            if(!curr) {
                table[index] = new Node(key, val);
                return;
            }

            // If not empty, i.e, key exists / collision
            // Traverse and add new key
            while(curr) {
                // check if the new key already exist or not
                // If exist update the value with new value
                if(curr->key == key) {
                    curr->val = val;
                    return;
                }

                // iterate
                curr = curr->next;
            }
            
            // Add new key at beg
            Node*  newNode = new Node(key, val);
            newNode->next = table[index];
            table[index] = newNode;
        }

        int get(int key) {

            // retrieve bucket index
            int index = hashFunction(key);

            // retrieve bucket head
            Node* curr = table[index];

            // Check if key exist in the bucket ll or not
            while(curr) {
                // find key
                if(curr->key == key) {
                    return curr->val;
                }

                // iterate
                curr = curr->next;
            }
            return -1;
        }

        void remove(int key) {
            
            // retrieve the bucket index
            int index = hashFunction(key);

            // retrive bucket head
            Node* curr = table[index];

            // define prev node to keep track of key
            Node* prev = nullptr;

            // Check key exist in the bucket or not
            while(curr) {
                // find key
                if(curr->key == key) {
                    
                    // check if it is head
                    if(!prev) {
                        table[index] = curr->next; // delete head
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

        bool containsKey(int key) {
            
            // retrieve the bucket index
            int index = hashFunction(key);

            // retrieve the bucket head
            Node* curr = table[index];

            // check key exist in bucket or not
            while(curr) {
                if(curr->key == key) {
                    return true;
                } 
                
                // iterate
                curr = curr->next;
            }
            return false;
        }

        void display() {
            
            // iterate total bucket head
            for(int i = 0; i < capacity; i++) {
                cout << i << ": ";
                
                // retrieve each bucket head
                Node* curr = table[i];

                // iterate over each bucket head
                while(curr) {
                    cout << "(" << curr->key << "," << curr->val << ") ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }
};

int main() {
    
    HashMap mp(5);

    mp.put(1, 10);
    mp.put(6, 60);  // collision with key 1
    mp.put(2, 20);

    mp.display();

    cout << "Get 6: " << mp.get(6) << endl;
    mp.remove(1);
    mp.display();

}