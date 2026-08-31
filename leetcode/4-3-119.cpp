#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 119. 杨辉三角 II
*/

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ans(0);
            vector<int> tri{1,1,1};
            for (int i = 2; i <= rowIndex; i++) {
                int begin = i * (i + 1) / 2;
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i) {
                        tri.push_back(1);
                        continue;
                    }
                    tri.push_back(tri[begin + j - i - 1] + tri[begin + j - i]);
                }
            }
            int begin = rowIndex * (rowIndex + 1) / 2;
            for (int i = 0; i <= rowIndex; i++) {
                ans.push_back(tri[begin + i]);
            }
            return ans;
        }
};

int main() {
    int n = 3;
    while(n--) {
        cout << n << endl;
    }
    return 0;
}