#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2535. 数组元素和与数字和的绝对差
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0, numSum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            eleSum += num;
            while(num) {
                numSum += num % 10;
                num /= 10;
            }
        }
        return abs(eleSum - numSum);
    }
};

int main() {


    return 0;
}