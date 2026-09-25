#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    LeetCode 2744. 最大字符串配对数目
*/

class Solution1 {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> count;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            string& s = words[i];
            ans += count[s];
            count[s]--;
            reverse(s.begin(), s.end());
            count[s]++;
        }
        return ans;
    }
};

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> seen;
        int ret = 0;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (seen.count(rev)) {
                ret++;
                seen.erase(rev);
            } else {
                seen.insert(s);
            }
        }
        return ret;
    }
};

int main() {
    
    return 0;
}