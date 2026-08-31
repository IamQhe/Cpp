#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 2367. 等差三元组的数目
*/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int next = nums[i] + diff;
            auto it = find(nums.begin() + i, nums.end(), next);
            int index1;
            if (it == nums.end()) {
                continue;
            }
            index1 = it - (nums.begin() + i);
            next += diff;
            auto it2 = find(nums.begin() + index1, nums.end(), next);
            if (it2 == nums.end()) {
                continue;
            }
            ans++;
        }
        return ans;
    }
};

int main() {


    return 0;
}