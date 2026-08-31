#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/*
    LeetCode LCR 123. 图书整理 I
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
    vector<int> reverseBookList1(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        int i = 0;
        for(; i < 10001; i++) {
            if(!curr) break;
            v.push_back(curr->val);
            curr = curr->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }

    vector<int> reverseBookList2(ListNode* head) {
        if (head == NULL) return {};

        ListNode* prev = head;
        ListNode* next = head->next;
        head->next = NULL;

        while(next) {
            head = next;
            next = head->next;
            head->next = prev;
            prev = head;
        }
        
        vector<int> ans;
        ListNode* curr = head;
        while(curr) {
            ans.push_back(curr->val);
            curr = curr->next;
        }
        return ans;
    }

    vector<int> reverseBookList3(ListNode* head) {
        vector<int> ans;
        while(head) {
            ans.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = ans.size() - 1;
        while(l < r) {
            int tmp = ans[l];
            ans[l] = ans[r];
            ans[r] = tmp;
            l++;
            r--;
        }
        return ans;
    }

    vector<int> reverseBookList(ListNode* head) {
        stack<int> st;
        while(head) {
            st.push(head->val);
            head = head->next;
        }

        vector<int> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};

int main() {


    return 0;
}