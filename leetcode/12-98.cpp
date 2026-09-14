#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 98. 验证二叉搜索树
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
    vector<int> arr;

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            arr.push_back(node->val);
            inOrder(node->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        arr.clear();
        inOrder(root);
        for(int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i-1]) return false;
        }
        return true;
    }
};

int main() {
    
    return 0;
}