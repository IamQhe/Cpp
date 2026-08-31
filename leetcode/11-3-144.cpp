#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 144. 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }

    void preOrder(TreeNode* node) {
        if (node) {
            ans.push_back(node->val);
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
};

int main() {


    return 0;
}