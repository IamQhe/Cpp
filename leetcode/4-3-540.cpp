#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 540. 有序数组中的单一元素
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main() {


    return 0;
}