#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1854. 人口最多的年份
*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int count[2051] = {0};
        int ret = -1;
        int maxCount = 0;
        for (int i = 0; i < logs.size(); i++) {
            for (int j = logs[i][0]; j < logs[i][1]; j++) {
                count[j]++;
            }
        }
        for (int i = 1950; i < 2051; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ret = i;
            }
        }
        return ret;
    }
};

int main() {
    
    return 0;
}