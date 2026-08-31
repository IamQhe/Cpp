#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 94. 二叉树的中序遍历
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            ans.push_back(node->val);
            inOrder(node->right);
        }
    }
};

int main() {


    return 0;
}