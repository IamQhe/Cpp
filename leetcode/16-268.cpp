#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 268. 丢失的数字
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }

        for (int i = 0; ; i++) {
            if (hash.find(i) == hash.end()) return i;
        }

        return -1;
    }
};

int main() {
    
    return 0;
}