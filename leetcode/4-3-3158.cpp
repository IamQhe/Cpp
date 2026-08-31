#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 3158. 求出出现两次数字的 XOR 值
*/

class Solution {
public:
    int duplicateNumbersXOR1(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    ans ^= nums[i];
                    nums[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }

    // 标记位
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long visited = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 判断是否出现过
            int x = nums[i];
            if (visited & (long long)1<<x) {
                ans ^= x;
            } else {
                visited |= ((long long)1<<x);
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}