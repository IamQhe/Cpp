#include <iostream>
using namespace std;

/*
    LeetCode 450. 删除二叉搜索树中的节点
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->val == key) {
                if (!root->left && !root->right) {
                    delete root;
                    return NULL;
                } else if (!root->right) {
                    TreeNode* leftChild = root->left;
                    delete root;
                    return leftChild;
                } else if (!root->left) {
                    TreeNode* rightChild = root->right;
                    delete root;
                    return rightChild;
                } else {
                    TreeNode* tmpNode = root->right;
                    while(tmpNode->left) {
                        tmpNode = tmpNode->left;
                    }
                    root->val = tmpNode->val;
                    root->right = deleteNode(root->right, tmpNode->val);
                }
            }
        }
        return root;
    }
};

int main() {
    
    return 0;
}