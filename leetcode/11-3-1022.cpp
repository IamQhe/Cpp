#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1022. 从根到叶的二进制数之和
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
    int ret = 0;
    int sumRootToLeaf(TreeNode* root) {
        sum(root, 0);
        return ret;
    }

    void sum(TreeNode* node, int val) {
        if (node) {
            val = (val << 1) + node->val;
            if (!node->left && !node->right) {
                ret += val;
                return;
            }
            sum(node->left, val);
            sum(node->right, val);
        }
    }
};

int main() {
    Solution s;
    TreeNode r7(0);
    TreeNode r6(1);
    TreeNode r5(0);
    TreeNode r4(1);
    TreeNode r3(0, &r6, &r7);
    TreeNode r2(1, &r4, &r5);
    TreeNode r1(1, &r3, &r2);
    
    s.sumRootToLeaf(&r1);


    return 0;
}