#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
    LeetCode 2390. 从字符串中移除星号
*/

class Solution {
public:
    string removeStars1(string s) {
        stack<char> stk;
        stack<char> tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
        }
        while(!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        string str = "";
        while (!tmp.empty()) {
            str += tmp.top();
            tmp.pop();
        }
        return str;
    }

    string removeStars(string s) {
        int l = 0, r = 0;
        string ret = "";
        for (; r < s.size(); r++) {
            if (s[r] == '*') {
                ret.pop_back();
                l = r+1;
                continue;
            }
            ret += s[l++];
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.removeStars("leet**cod*e");

    return 0;
}