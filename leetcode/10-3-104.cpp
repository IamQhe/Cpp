#include <iostream>
#include <stack>
using namespace std;

/*
    LeetCode 104. 二叉树的最大深度
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
    // 递归
    int maxDepth1(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // 迭代
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
    }
};

int main() {


    return 0;
}