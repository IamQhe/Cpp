#include <iostream>
using namespace std;

/*
    LeetCode 1302. 层数最深叶子节点的和
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
    int maxDepth;
    int deepestLeavesSum(TreeNode* root) {
        maxDepth = 0;
        sum = 0;
        getDeep(root, 0);
        getSum(root, 0);
        return sum;
    }

    void getDeep(TreeNode* node, int depth) {
        if (node) {
            depth++;
            if (depth > maxDepth) maxDepth = depth;
            getDeep(node->left, depth);
            getDeep(node->right, depth);
        }
    }

    void getSum(TreeNode* node, int depth) {
        if (node) {
            depth++;
            if (depth == maxDepth) sum += node->val;
            getSum(node->left, depth); 
            getSum(node->right, depth); 
        }
    }
};

int main() {


    return 0;
}