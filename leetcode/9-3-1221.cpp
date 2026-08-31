#include <iostream>
using namespace std;

/*
    LeetCode 1221. 分割平衡字符串
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == 0) {
                ret++;
            }
        }
        return ret;
    }
};

int main() {


    return 0;
}