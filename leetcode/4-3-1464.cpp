#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1464. 数组中两元素的最大乘积
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int ans = -100000000;
        for(int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                ans = max((nums[i] - 1) * (nums[j] - 1), ans);
            }
        }
    }
};

int main() {


    return 0;
}