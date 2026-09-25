#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2150. 找出数组中的所有孤独数字
*/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i] == 1 && hash[nums[i] - 1]] == 0 && hash[nums[i] + 1] == 0) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}