#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2670. 找出不同元素数目差数组
*/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = 1;
            ans.push_back(hash.size());
        }

        hash.clear();
        for (int i = nums.size() - 1; i >= 1; i--) {
            hash[nums[i]] = 1;
            ans[i - 1] -= hash.size();
        }
        return ans;
    }
};

int main() {
    
    return 0;
}