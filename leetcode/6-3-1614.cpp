#include <iostream>
#include <stack>
using namespace std;

/*
    LeetCode 1614. 括号的最大嵌套深度
*/

class Solution {
public:
    int maxDepth1(string s) {
        stack<char> st;
        int maxDeep = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                maxDeep = st.size() > maxDeep ? st.size() : maxDeep;
            } else if (s[i] == ')') {
                if (st.top() == '(') {
                    st.pop();
                }
            }
        }
        return maxDeep;
    }

    int maxDepth(string s) {
        int ans = 0, top = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                top++;
                ans = max(top, ans);
            } else if (s[i] == ')') {
                top--;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}