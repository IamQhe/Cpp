#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 145. 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            ans.push_back(node->val);
        }
    }
};

int main() {


    return 0;
}