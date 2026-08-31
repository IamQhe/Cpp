#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1991. 找到数组的中间位置
*/

class Solution {
public:
    int findMiddleIndex1(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int ls = 0, rs = 0;
            for(int j = 0; j < i; j++) {
                ls += nums[j];
            }
            for(int j = nums.size() - 1; j > i; j--) {
                rs += nums[j];
            }
            if (ls == rs) return i;
        }
        return -1;
    }

    // 前缀和
    int findMiddleIndex(vector<int>& nums) {
    }
};

int main() {


    return 0;
}