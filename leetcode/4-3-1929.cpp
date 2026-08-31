#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1929. 数组串联
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            arr.push_back(nums[i]);
        }
        for(int i = 0; i < len; i++) {
            arr.push_back(nums[i]);
        }
        return arr;
    }
};

int main() {


    return 0;
}