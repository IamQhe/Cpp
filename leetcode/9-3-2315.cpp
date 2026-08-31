#include <iostream>
using namespace std;

/*
    LeetCode 2315. 统计星号
*/

class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '|') {
                cnt++;
                continue;
            }
            if (cnt % 2 == 1) {
                continue;
            }
            if (s[i] == '*') {
                ret++;
            }
        }
        return ret;
    }
};

int main() {


    return 0;
}