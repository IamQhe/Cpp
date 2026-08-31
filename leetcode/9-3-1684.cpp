#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1684. 统计一致字符串的数目
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26];
        for (int i = 0; i < allowed.size(); i++) {
            arr[allowed[i] - 'a'] = 1;
        }

        int cnt = 0;
        for(int i = 0; i < words.size(); i++) {
            bool flag = true;
            for(int j = 0; j < words[i].size(); j++) {
                if (!arr[words[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};

int main() {


    return 0;
}