#include <iostream>
using namespace std;

/*
    LeetCode 876. 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast->next ? slow->next : slow;
    }

    ListNode* middleNode1(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            fast = fast->next;
            if(!fast) {
                return slow;
            }
            fast = fast->next;
            if(!fast) {
                return slow->next;
            }
            slow = slow->next;
        }
        return NULL;
    }
};

int main() {


    return 0;
}