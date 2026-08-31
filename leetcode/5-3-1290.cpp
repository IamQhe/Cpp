#include <iostream>
using namespace std;

/*
    LeetCode 1290. 二进制链表转整数
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
        int getDecimalValue(ListNode* head) {
            ListNode* cur = head;
            int ans = 0;
            while(cur) {
                ans <<= 1;
                ans += cur->val;
                cur = cur->next;
            }
            return ans;
        }
};

int main() {

    return 0;
}