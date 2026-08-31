#include <iostream>
#include <stack>
using namespace std;

/*
    LeetCode LCR 027. 回文链表
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
    bool isPalindrome(ListNode* head) {
        int len;
        ListNode* curr = head;
        while(curr) {
            len++;
            curr = curr->next;
        }
        
        int n = len / 2;
        stack<int> st;
        while(n--) {
            st.push(head->val);
            head = head->next;
        }
        if (len & 1) {
            head = head->next;
        }

        while(!st.empty()) {
            if (st.top() != head->val) return false;
            st.pop();
            head = head->next;
        }
        return true;
    }
};

int main() {


    return 0;
}