#include <iostream>
using namespace std;

/*
    LeetCode LCR 140. 训练计划 II
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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* fast = head;
        while(cnt--) {
            fast = fast->next;
        }
        ListNode* slow = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {


    return 0;
}