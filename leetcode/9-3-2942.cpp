#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2942. 查找包含给定字符的单词
*/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}