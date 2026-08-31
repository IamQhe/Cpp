#include <iostream>
using namespace std;

/*
    LeetCode 2236. 判断根结点是否等于子结点之和
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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main() {


    return 0;
}