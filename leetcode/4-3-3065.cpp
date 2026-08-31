#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 3065. 超过阈值的最少操作数 I
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size();i++) {
            if (nums[i] < k) ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2,4,9};
    int k = 1;
    cout << s.minOperations(nums, k) << endl;

    return 0;
}