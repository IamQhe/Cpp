#include <iostream>
#include <string>
using namespace std;

/*
    LeetCode 1876. 长度为三且各字符不同的子字符串
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0;
        int cnt = 0;
        for (int i = 0; i < s.size() - 2; i++) {
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    int ans = s.countGoodSubstrings("icolgrjedehnd");
    cout << ans << endl;
    return 0;
}