#include <iostream>
using namespace std;

/*
    LeetCode LCR 175. 计算二叉树的深度
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
    int calculateDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {


    return 0;
}