#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    LeetCode 1624. 两个相同字符之间的最长子字符串
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int hash[256];
        memset(hash, -1, sizeof(hash));

        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == -1) {
                hash[s[i]] = i;
            } else {
                ans = max(ans, i - hash[s[i]] - 1);
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}