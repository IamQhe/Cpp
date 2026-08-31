#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2824. 统计和小于目标的下标对数目
*/

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) ans++;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}