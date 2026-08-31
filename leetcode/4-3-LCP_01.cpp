#include <iostream>
#include <vector>
using namespace std;

/*
    leetcode LCP 01. 猜数字
*/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]) ans++;
        }
        return ans;
    }
};

int main() {


    return 0;
}