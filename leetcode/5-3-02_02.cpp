#include <iostream>
using namespace std;

/*
    LeetCode 面试题 02.02. 返回倒数第 k 个节点
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
    int kthToLast1(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }
        for(int i = 0; i < len - k; i++) {
            head = head->next;
        }
        return head->val;
    }

    // 快慢指针
    int kthToLast(ListNode* head, int k) {
        ListNode* fast = head;
        while(k--) {
            fast = fast->next;
        }
        ListNode* slow = head;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};

int main() {


    return 0;
}