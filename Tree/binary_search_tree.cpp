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

class BST {
    private:
        TreeNode* root;

        void insertBST(TreeNode* &root, int val) {
            // check if empty
            if(!root) {
                root = new TreeNode(val);
                return;
            }

            if(val < root->data) {
                insertBST(root->left, val);
            }
            else if(val > root->data) {
                insertBST(root->right, val);
            }
        }

        TreeNode* findMin(TreeNode* root) {
            if(root && root->left) {
                root = findMin(root->left);
            }
            return root;
        }

    public:
        BST(): root(nullptr) {};

        TreeNode* getRoot() {
            return root;
        }

        void insert(int val) {
            insertBST(root, val);
        }
        
        void levelorder(TreeNode* root) {
            // if tree empty
            if(!root) return;

            // create queue
            queue<TreeNode*> q;

            // push root
            q.push(root);

            // iterate until queue becomes empty
            while(!q.empty()) {

                // retrive curr TreeNode in queue & pop it
                TreeNode* curr = q.front();
                q.pop();

                // process curr TreeNode
                cout << curr->data << " ";

                // push left if exist
                if(curr->left) q.push(curr->left);

                // push right if exist
                if(curr->right) q.push(curr->right);
            }
        }

        void preorder(TreeNode* root) {
            if(!root) return;

            // proccess root
            cout << root->data << " ";

            // go left
            preorder(root->left);

            // go right
            preorder(root->right);
        }

        void inorder(TreeNode* root) {
            if(!root) return;

            // go left
            inorder(root->left);

            // process root
            cout << root->data << " ";

            // go right
            inorder(root->right);
        }

        void postorder(TreeNode* root) {
            if(!root) return;

            // go left
            postorder(root->left);

            // go right
            postorder(root->right);

            // process root
            cout << root->data << " ";
        }

        void deleteTree(TreeNode* root) {
            if(!root) return;

            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }

        void deleteVal(TreeNode* &root, int val) {
            // if empty
            if(!root) return;

            // find elem
            if(val < root->data) {
                deleteVal(root->left, val);
            }
            else if(val > root->data) {
                deleteVal(root->right, val);
            }
            else {
                // solve for case 1 & 2
                if(!root->left && !root->right) {
                    delete root;
                    root = nullptr;
                    return;
                }
                else if(!root->right) {
                    TreeNode* temp = root;
                    root = root->left;
                    delete temp;
                    return;
                }
                else if(!root->left) {
                    TreeNode* temp = root;
                    root = root->right;
                    delete temp;
                    return;
                }
                else { // case 3
                    TreeNode* min = findMin(root->right);
                    root->data = min->data;

                    // delete the min node
                    deleteVal(root->right, min->data);

                }
            }
        }

        bool searchBST(TreeNode* root, int key) {
            if(!root) return false;
            if(root->data == key) return true;

            if(key < root->data) {
                return searchBST(root->left, key);
            }
            else {
                return searchBST(root->right, key);
            }
        }
};

int main() {

    BST bst;

    bst.insert(45);
    bst.insert(2);
    bst.insert(10);
    bst.insert(15);
    bst.insert(12);
    bst.insert(20);
    bst.insert(25);
    bst.insert(30);
    bst.insert(40);
    bst.insert(27);
    bst.insert(48);
    bst.insert(50);
    bst.insert(55);
    bst.insert(60);

    TreeNode* root = bst.getRoot();

    cout << "Preorder: ";
    bst.preorder(root);

    cout << "\nInorder: ";
    bst.inorder(root);

    cout << "\nPostorder: ";
    bst.postorder(root);

    cout << "\nLevelorder: ";
    bst.levelorder(root);
    
    cout << "\nElement found: " << bst.searchBST(root, 27);

    bst.deleteVal(root, 27);

    cout << "\nElement found: " << bst.searchBST(root, 27);


    // delete
    bst.deleteTree(root);
    root = nullptr;

    cout << "\nLevelorder: ";
    bst.levelorder(root);



}