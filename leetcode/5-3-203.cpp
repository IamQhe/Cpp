#include <iostream>
using namespace std;

/*
    LeetCode 203. 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* pre = newHead;
        while(pre->next) {
            if(pre->next->val == val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return newHead->next;
    }
};

int main() {


    return 0;
}