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

    // delete
    bst.deleteTree(root);
    root = nullptr;

    cout << "\nLevelorder: ";
    bst.levelorder(root);


}