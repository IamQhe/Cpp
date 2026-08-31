#include <iostream>
using namespace std;

/*
    LeetCode 965. 单值二叉树
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
    bool isUnivalTree(TreeNode* root) {
        return isUnival(root, root->val);
    }

    bool isUnival(TreeNode* node, int val) {
        if (!node) return true;
        if (node->val != val) return false; 
        return isUnival(node->left, val) && isUnival(node->right, val);
    }
};

int main() {


    return 0;
}