#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2859. 计算 K 置位下标对应元素的和
*/

class Solution {
    public:
        int sumIndicesWithKSetBits(vector<int>& nums, int k) {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                int cnt = 0;
                int x = i;
                while (x) {
                    if (x & 1) {
                        cnt++;
                    }
                    x >>= 1;
                }
                if (cnt == k) {
                    sum += nums[i];
                }
            }
            return sum;
        }
};

int main() {
    Solution s;
    vector<int> v = {5, 10, 1, 5, 2};
    cout << s.sumIndicesWithKSetBits(v, 1);

    return 0;
}