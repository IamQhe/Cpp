#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2487. 从链表中移除节点
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // 单调栈
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stk;
        ListNode* curr = head;
        while(curr) {
            while(stk.size() && stk.back()->val < curr->val) {
                stk.pop_back();
            }
            stk.push_back(curr);
            curr = curr->next;
        }
        for(int i = 0; i < stk.size() - 1; i++) {
            stk[i]->next = stk[i+1];
        }
        stk.back()->next = NULL;
        return stk[0];
    }
};

int main() {


    return 0;
}