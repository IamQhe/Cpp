#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2341. 数组能形成多少数对
*/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) {
                continue;
            }
            for(int j = i+1; j < nums.size(); j++) {
                if (nums[j] == -1) {
                    continue;
                }
                if (nums[i] == nums[j]) {
                    nums[i] = -1;
                    nums[j] = -1;
                    pairs++;
                }
            }
        }
        return vector<int>{pairs, (int)nums.size() - pairs * 2};
    }
};

int main() {


    return 0;
}