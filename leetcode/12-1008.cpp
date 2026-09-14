#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 1008. 前序遍历构造二叉搜索树
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
    TreeNode* getBST(vector<int> preorder, int l, int r) {
        if (l > r) return NULL;
        TreeNode* node = new TreeNode(preorder[l]);
        int i;
        for(i = l + 1; i <= r; i++) {
            if (preorder[i] > preorder[l]) break;
        }
        node->left = getBST(preorder, l+1, i - 1); 
        node->right = getBST(preorder, i, r);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return getBST(preorder, 0, preorder.size() - 1);
    }
};

int main() {
    
    return 0;
}