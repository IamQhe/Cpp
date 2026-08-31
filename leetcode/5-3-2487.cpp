#include <iostream>
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

    // 递归
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* nextHead = removeNodes(head->next);
        if (nextHead->val > head->val) {
            return nextHead;
        } else {
            head->next = nextHead;
        }
        return head;
    }

    ListNode* removeNodes1(ListNode* head) {
        if (head == NULL) return head;
        head->next = removeNodes1(head->next);
        if (head->next == NULL) {
            return head;
        }
        if (head->val < head->next->val) {
            return head->next;
        }
        return head;
    }
};

int main() {


    return 0;
}