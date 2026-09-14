#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode LCR 174. 寻找二叉搜索树中的目标节点
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
    vector<int> nums;

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            nums.push_back(node->val);
            inOrder(node->right);
        }
    }

    int findTargetNode(TreeNode* root, int cnt) {
       nums.clear();
       inOrder(root);
       return nums[nums.size() - cnt];
    }
};

int main() {
    
    return 0;
}