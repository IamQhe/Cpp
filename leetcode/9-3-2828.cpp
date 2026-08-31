#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2828. 判别首字母缩略词
*/

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;
        int i;
        for( i = 0; i < words.size(); i++) {
            if (words[i][0] != s[i]) return false;
        }
        return true;
    }
};

int main() {


    return 0;
}