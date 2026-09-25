#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

/*
    LeetCode 面试题 17.04. 消失的数字
*/

class Solution1 {
public:
    bool N[100000];
    int missingNumber(vector<int>& nums) {
        memset(N, 0, sizeof(N));
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            N[nums[i]] = true;
        }
        int index;
        for (index = 0; index < n; index++) {
            if (!N[index]) return index;
        }
        return index;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map[nums[i]] = 1;
        }
        for (int i = 0; i <= n; i++) {
            if (map.find(i) == map.end()) return i;
        }
        return 0;
    }
};

int main() {
    
    return 0;
}