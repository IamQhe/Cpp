#include <iostream>
using namespace std;

/*
    LeetCode LCR 024. 反转链表
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
    // 循环
    ListNode* reverseList1(ListNode* head) {
        if (head == NULL) return head;
        ListNode* prev = head;
        ListNode* next = head->next;
        head->next = NULL;
        while(next) {
            head = next;
            next = head->next;
            head->next = prev;
            prev = head;
        }
        return head;
    }

    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

int main() {


    return 0;
}