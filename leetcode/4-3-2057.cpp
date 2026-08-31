#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2057 值相等的最小索引
*/

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if( (i % 10) == nums[i]) return i;
        }
        return -1;
    }
};

int main() {


    return 0;
}