#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1920. 基于排列构建数组
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            arr[i] = nums[nums[i]];
        }
        return arr;
    }
};

int main() {


    return 0;
}