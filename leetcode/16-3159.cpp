#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    LeetCode 3159. 查询数组中元素的出现位置
*/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int index[100001];
        memset(index, -1, sizeof(index));
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                index[cnt++] = i; 
            }
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(index[queries[i]]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}