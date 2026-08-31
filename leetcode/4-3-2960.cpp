#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2960. 统计已测试设备
*/

class Solution {
public:
    int countTestedDevices1(vector<int>& batteryPercentages) {
        int ans = 0;
        for(int i = 0; i < batteryPercentages.size(); i++) {
            if(batteryPercentages[i] == 0) {
                continue;
            } else {
                for (int j = i + 1; j < batteryPercentages.size(); j++) {
                    if (batteryPercentages[j] > 0) batteryPercentages[j]--;
                }
                ans++;
            }
        }
        return ans;
    }

    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < batteryPercentages.size(); i++) {
            if (batteryPercentages[i] > 0 && batteryPercentages[i] > cur) {
                ans++;
                cur++;
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}