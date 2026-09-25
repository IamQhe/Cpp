#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2965. 找出缺失和重复的数字
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> hash;
        int n = grid.size();
        int total = n * n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash[grid[i][j]]++;
            }
        } 
        int miss = 0;
        int multi = 0;
        for (int i = 1; i <= total; i++) {
            if (hash.find(i) == 0) {
                miss = i;
            } else if (hash[i] == 2) {
                multi = i;
            }
            if (miss != 0 && multi != 0) break;
        }
        return {multi, miss};
    }
};

int main() {
    
    return 0;
}