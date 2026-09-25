#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
    LeetCode 3146. 两个字符串的排列差
*/

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int count[256];
        memset(count, -1, sizeof(count));
        for (int i = 0; i < s.size(); i++) {
            count[s[i]] = i;
        }
        int sum = 0;
        for (int i = 0; i < t.size(); i++) {
            sum += abs(count[t[i]] - i);
        }
        return sum;
    }
};

int main() {
    
    return 0;
}