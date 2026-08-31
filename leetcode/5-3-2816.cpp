#include <iostream>
using namespace std;

/*
    LeetCode 2816. 翻倍以链表形式表示的数字
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
    ListNode* doubleIt1(ListNode* head) {
        int carry = getCarry1(head->next);
        int db = head->val * 2 + carry;
        if (db >= 10) {
            head->val = db % 10;
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        head->val = db;
        return head;

    }

    int getCarry1(ListNode* head) {
        if (head == NULL) return 0;
        int carry = getCarry1(head->next);
        int db = head->val * 2 + carry;
        if (db >= 10) {
            head->val = db % 10;
            return 1;
        }
        head->val = db;
        return 0;
    }

    // 简化版：
    ListNode* doubleIt(ListNode* head) {
        int val;
        doDouble(head, &val);
        if (val) {
            return new ListNode(val, head);
        }
        return head;
    }

    void doDouble(ListNode* head, int* carry) {
        if (head == NULL) {
            *carry = 0; 
            return;
        }
        int val;
        doDouble(head->next, &val);
        head->val = head->val * 2 + val;
        *carry = head->val / 10;
        head->val %= 10;
    }
};

int main() {


    return 0;
}