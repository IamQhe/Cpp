#include <iostream>
using namespace std;

/*
    LeetCode 19. 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* newHead = new ListNode();
        newHead->next = head;

        ListNode* fast = head;
        ListNode* slow = head;
        while(n--) {
            fast = fast->next;
        }

        if(!fast) {
            newHead->next = head->next;
            return newHead->next;
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        if (slow->next->next) {
            slow->next = slow->next->next;
        } else {
            slow->next = NULL;
        }
        
        return newHead->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }

        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if(!prev) {
            return head->next;
        }

        prev->next = slow->next;
        return head;
    }
};

int main() {


    return 0;
}