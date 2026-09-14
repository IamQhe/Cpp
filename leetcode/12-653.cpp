#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 653. 两数之和 IV - 输入二叉搜索树
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

    bool inOrder1(TreeNode* node, int k) {
        if (node) {
            if (inOrder1(node->left, k)) return true;
            int val = node->val;
            for(int i = 0; i < ret.size(); i++) {
                if (val + ret[i] == k) return true;
            }
            ret.push_back(node->val);
            if (inOrder1(node->right, k)) return true;
            return false;
        }
        return false;
    }

    bool findTarget1(TreeNode* root, int k) {
        ret.clear();
        return inOrder1(root, k);
    }

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            ret.push_back(node->val);
            inOrder(node->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        ret.clear();
        inOrder(root);
        int l = 0, r = ret.size() - 1;
        while(l < r) {
            int sum = ret[l] + ret[r];
            if (k < sum) {
                r--;
            } else if (k > sum) {
                l++;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}