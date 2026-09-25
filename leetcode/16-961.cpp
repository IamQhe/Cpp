#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    LeetCode 961. 在长度 2N 的数组中找出重复 N 次的元素
*/

class Solution1 {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        int n = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] == n) return nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[0] == nums[n / 2] ? nums[0] : nums[n / 2]; 
    }
};

int main() {
    
    return 0;
}