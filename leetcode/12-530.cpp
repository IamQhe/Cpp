#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    LeetCode 530. 二叉搜索树的最小绝对差
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
    int pre;
    int ret;

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            ret = min(node->val - pre, ret);
            pre = node->val;
            inOrder(node->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        pre = -100000;
        ret = 100000;
        inOrder(root);
        return ret;
    }
};

int main() {
    
    return 0;
}