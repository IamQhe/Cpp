#include <iostream>
#include <queue>
using namespace std;

/*
    LeetCode 222. 完全二叉树的节点个数
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
    // 广搜
    int countNodes1(TreeNode* root) {
        if (!root) return 0;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        cnt++;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                cnt++;
            }
            if (node->right) {
                q.push(node->right);
                cnt++;
            }
        }
        return cnt;
    }

    // 递归
    int countNodes2(TreeNode* root) {
        if (!root) return 0;
        int leftNum = countNodes2(root->left);
        int rightNum = countNodes2(root->right);
        return leftNum + rightNum + 1;
    }

    // 普通和满二叉树结合
    int countNodes(TreeNode* root) {
        TreeNode* l = root;
        TreeNode* r = root;
        int ld = 0, rd = 0;
        while(l) {
            ld++;
            l = l->left;
        }
        while(r) {
            rd++;
            r = r->right;
        }
        if (ld == rd) return (1 << rd) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {


    return 0;
}