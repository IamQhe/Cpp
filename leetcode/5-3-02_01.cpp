#include <iostream>
using namespace std;

/*
    LeetCode 面试题 02.01. 移除重复节点
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL) return NULL;
        int hash[20001] = {0};
        ListNode* tmp = head;
        ListNode* curr = head->next;
        hash[head->val] = 1;
        while(curr) {
            if (!hash[curr->val]) {
                hash[curr->val] = 1;
                tmp->next = curr;
                tmp = tmp->next;
            }
            curr = curr->next; 
        }
        tmp->next = NULL;
        return head;
    }
};

int main() {


    return 0;
}