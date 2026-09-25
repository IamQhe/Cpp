#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    LeetCode 41. 缺失的第一个正数
*/

class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 1 && nums[0] != 1) return 1;
        sort(nums.begin(), nums.end());
        int positiveNum = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                positiveNum = nums[i];
                index = i;
                break;
            }
        }

        if (positiveNum != 1) return 1;

        int curr = 1;
        int pre = -1;
        while (index < nums.size()){
            if (positiveNum == pre) {
                positiveNum = nums[++index];
                continue;
            }
            if (curr != positiveNum) {
                return curr;
            } else {
                if (index == nums.size() - 1) {
                    return curr == positiveNum ? curr + 1 : curr;
                }
                pre = positiveNum;
                positiveNum = nums[++index];
                curr++;
            }
        }
        return curr;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }

        for (int i = 1; ; i++) {
            if (hash.find(i) == hash.end()) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    
    return 0;
}