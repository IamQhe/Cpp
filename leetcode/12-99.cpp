#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 99. 恢复二叉搜索树
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
    vector<TreeNode*> ret;

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            ret.push_back(node);
            inOrder(node->right);
        }
    }

    void recoverTree(TreeNode* root) {
        ret.clear();
        inOrder(root);
        TreeNode* x;
        TreeNode* y;
        for(int i = 0; i < ret.size() - 1; i++) {
            if (ret[i]->val > ret[i + 1]->val) {
                y = ret[i + 1];
                if (!x) {
                    x = ret[i];
                }
            }
        }
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};

int main() {
    
    return 0;
}