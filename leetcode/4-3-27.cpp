#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 27. 移除元素
*/

class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        int k = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val) {
                for(int j = i; j < nums.size() - 1; j++) {
                    nums[j] = nums[j + 1];
                }
            } else {
                k++;
            }      
        }
        return k;
    }

    // 双指针
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if(nums[l] == val) {
                nums[l] = nums[r];
                r--;
            } else {
                l++;
            }
        }
        return r + 1;
    }
};

int main() {
    Solution s;
    vector v = {0,1,2,2,3,0,4,2};
    int ans = s.removeElement(v, 2);
    cout << ans << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}