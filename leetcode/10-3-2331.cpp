#include <iostream>
using namespace std;

/*
    LeetCode 2331. 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};

int main() {


    return 0;
}