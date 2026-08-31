#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2656. K 个元素的最大和
*/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) max = nums[i];
        }
        return k * max + (k * (k-1)) / 2;
    }
};

int main() {
    Solution s;
    vector v = {1, 2, 3, 4, 5};
    int ans = s.maximizeSum(v, 3);

    return 0;
}