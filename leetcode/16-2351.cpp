#include <iostream>
#include <cstring>
using namespace std;

/*
    LeetCode 2351. 第一个出现两次的字母
*/

class Solution {
public:
    char repeatedCharacter(string s) {
        int hash[256];
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 1) {
                return s[i];
            }
            hash[s[i]]++;
        }
        return ' ';
    }
};

int main() {
    
    return 0;
}