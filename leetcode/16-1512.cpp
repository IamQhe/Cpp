#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 1512. 好数对的数目
*/

class Solution1 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]].push_back(i);
            } else {
                for (int j = 0; j < hash[nums[i]].size(); j++) {
                    if (i > hash[nums[i]][j]) ans++;
                }
                hash[nums[i]].push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += hash[nums[i]];
            hash[nums[i]]++;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}