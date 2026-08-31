#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2006. 差的绝对值为 K 的数对数目
*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                int diff = nums[i] - nums[j];
                if(diff == k || (~diff + 1) == k) ans++;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}