#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2114. 句子中的最多单词数
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < sentences[i].size(); j++) {
                if (sentences[i][j] == ' ') {
                    cnt++;
                }
            }
            max = cnt > max ? cnt : max;
        }
        return max + 1;
    }
};

int main() {


    return 0;
}