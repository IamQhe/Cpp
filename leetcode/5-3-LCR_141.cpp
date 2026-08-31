#include <iostream>
using namespace std;

/*
    LeetCode LCR 141. 训练计划 III
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
    ListNode* trainningPlan(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = trainningPlan(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

int main() {


    return 0;
}