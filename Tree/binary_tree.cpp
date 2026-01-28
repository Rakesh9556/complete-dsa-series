#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BinaryTree {
    private:
        TreeNode* root;

        void insertLevelOrder(TreeNode*& root, int val) {
            // if empty tree
            if(!root) {
                root = new TreeNode(val);
                return;
            }
            
            // create queue
            queue<TreeNode*> q;

            // push root
            q.push(root);

            // iterate queue untill empty
            while(!q.empty()) {
                
                // Access front and pop it
                TreeNode* curr = q.front();
                q.pop();

                // process left - if missing insert
                if(curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    return;
                }
                else q.push(curr->left);

                //process right - if missing insert
                if(curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    return;
                }
                else q.push(curr->right);
            }
        }

    public:
        BinaryTree(): root(nullptr) {};

        TreeNode* getRoot() {
            return root;
        }

        void insert(int val) {
           insertLevelOrder(root, val); 
        }

        void preorder(TreeNode* root) {
            // base case
            if(!root) return;
            
            // process root
            cout << root->data << " ";

            // go left
            preorder(root->left);

            // go right
            preorder(root->right);

        }

        void inorder(TreeNode* root) {
            // base case
            if(!root) return;

            // go left
            inorder(root->left);

            // process root
            cout << root->data << " ";

            // go right
            inorder(root->right);
        }

        void postorder(TreeNode* root) {
            // base case
            if(!root) return;

            // go left
            postorder(root->left);

            // go right
            postorder(root->right);

            // process root
            cout << root->data << " ";
        }

        void levelorder(TreeNode* root) {
            // if root empty
            if(!root) return;

            // create queue
            queue <TreeNode*> q;

            // push root
            q.push(root);

            // while queue is not empty
            while(!q.empty()) {
                // pop front
                TreeNode* curr = q.front();
                q.pop();

                // process curr node
                cout << curr->data << " ";

                // push left if exist
                if(curr->left) q.push(curr->left); 

                // push right if exist
                if(curr->right)  q.push(curr->right);
            }
        }

        void deleteTree(TreeNode* root) {
            // base case
            if(!root) return;

            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }

};


int main() {

    /* Manual Tree Creation
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    // attaching child nodes
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    */

    BinaryTree t;

    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(2);
    t.insert(7);
    
    TreeNode* root = t.getRoot();

    cout << "Preorder: ";
    t.preorder(root);

    cout << "\nInorder: ";
    t.inorder(root);

    cout << "\nPostorder: ";
    t.postorder(root);

    cout << "\nLevelorder: ";
    t.levelorder(root);

    // delete
    t.deleteTree(root);
    root = nullptr;

    cout << "\nLevelorder: ";
    t.levelorder(root);

}