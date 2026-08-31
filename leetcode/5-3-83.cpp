#include <iostream>
using namespace std;

/*
    LeetCode 83. 删除排序链表中的重复元素
*/

struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* cur = head;
            int preValue;
            while(cur) {
                if (cur->next) {
                    if (cur->val == cur->next->val) {
                        cur->next = cur->next->next;
                    } else {
                        cur = cur->next;
                    }
                } else {
                    cur = cur->next;
                }
            }
            return head;
        }
};

int main() {
    Solution s;
    ListNode* node4;
    ListNode* node3;
    ListNode* node2;
    ListNode* node1;
    ListNode* head;
    head->val = 1;
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    s.deleteDuplicates(head);
    return 0;
}