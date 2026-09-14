#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 654. 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }

    TreeNode* build(int start, int end, vector<int>& nums) {
        if (start > end) return NULL;
        int max = -1;
        int index = -1;
        for (int i = start; i <= end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(max);
        node->left = build(start, index - 1, nums);
        node->right = build(index + 1, end, nums);
        return node;
    }
};

int main() {
    
    return 0;
}