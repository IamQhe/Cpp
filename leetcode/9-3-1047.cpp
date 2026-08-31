#include <iostream>
using namespace std;

/*
    LeetCode 1047. 删除字符串中的所有相邻重复项
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string ret = "";
        for(int i = 0; i < s.size(); i++) {
            if (ret.size() > 0 && ret.back() == s[i]) {
                ret.pop_back();
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    s.removeDuplicates("azxxzy");

    return 0;
}