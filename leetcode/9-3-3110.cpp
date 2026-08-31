#include <iostream>
#include <string>
using namespace std;

/*
    LeetCode 3110. 字符串的分数
*/

class Solution {
public:
    int scoreOfString(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return (int)s[0];
        int score = 0;
        for (int i = 1; i < s.size(); i++) {
            int diff = s[i] - s[i-1];
            if (diff < 0) {
                score += ~diff + 1;
            } else {
                score += diff;
            }
        }
        return score;
    }
};

int main() {


    return 0;
}