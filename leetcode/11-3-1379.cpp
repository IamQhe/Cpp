#include <iostream>
using namespace std;

/*
    LeetCode 1379. 找出克隆二叉树中的相同节点
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
    TreeNode* ret;
    TreeNode* getTargetCopy1(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        preOrder(cloned, target->val);
        return ret;
    }

    void preOrder(TreeNode* node, int val) {
        if (node) {
            if (node->val == val) {
                ret = node;
                return;
            }
            preOrder(node->left, val);
            preOrder(node->right, val);
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }
        if (!original) return NULL;
        if (original->left) {
            TreeNode* t = getTargetCopy(original->left, cloned->left, target);
            if (t) {
                return t;
            }
        }
        if (original->right) {
            TreeNode* t = getTargetCopy(original->left, cloned->left, target);
            if (t) {
                return t;
            }
        }
        return NULL;
    }
};

int main() {


    return 0;
}