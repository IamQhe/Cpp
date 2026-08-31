#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    LeetCode 739. 每日温度
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stk;
        vector<int> ans(temperatures.size());

        for(int i = 0; i < temperatures.size(); i++) { 
            while (stk.size() && temperatures[i] > temperatures[stk.back()]) {
                    ans[stk.back()] = i - stk.back();
                    stk.pop_back();
            }
            stk.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {73,74,75,71,69,72,76,73};
    vector<int> ans = s.dailyTemperatures(v);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}