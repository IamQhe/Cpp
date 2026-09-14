#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 501. 二叉搜索树中的众数
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
    vector<int> ret;
    int pre;
    int cnt;
    int max;

    void visit(TreeNode* node) {
        if (node->val == pre) {
            cnt++;
        } else {
            pre = node->val;
            cnt = 1;
        }

        if (cnt > max) {
            max = cnt;
            ret.clear();
            ret.push_back(node->val);
        } else if (cnt == max) {
            ret.push_back(node->val);
        }
    }

    void inOrder(TreeNode* node) {
        if(node) {
            inOrder(node->left);
            visit(node);
            inOrder(node->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        ret.clear();
        pre = -1000000;
        cnt = 0;
        max = 0;
        inOrder(root);
        return ret;
    }
};

int main() {
    
    return 0;
}