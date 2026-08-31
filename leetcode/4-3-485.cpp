#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 485. 最大连续 1 的个数
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cur++;
                if (cur > max ) {
                    max = cur;
                }
            } else {
                cur = 0;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}