#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 108. 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size() - 1);
    }

    TreeNode* insert(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = insert(nums, l, mid - 1);
        node->right = insert(nums, mid + 1, r);
        return node; 
    }
};

int main() {
    
    return 0;
}