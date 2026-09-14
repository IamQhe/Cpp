#include <iostream>
using namespace std;

/*
    LeetCode 938. 二叉搜索树的范围和
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
    int sum;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sum = 0;
        if (root->val <= high && root->val >= low) {
            sum += root->val;
        }
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};

int main() {
    
    return 0;
}