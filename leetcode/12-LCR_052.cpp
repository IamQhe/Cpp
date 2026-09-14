#include <iostream>
using namespace std;

/*
    LeetCode LCR 052. 递增顺序搜索树
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
    TreeNode* ans;
    TreeNode* tmp;
    TreeNode* increasingBST(TreeNode* root) {
        ans = NULL;
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            if (!ans) {
                ans = new TreeNode(node->val);
                tmp = ans;
            } else {
                tmp->right = new TreeNode(node->val);
                tmp = tmp->right;
            }
            inOrder(node->right);
        }
    }
};

int main() {
    
    return 0;
}