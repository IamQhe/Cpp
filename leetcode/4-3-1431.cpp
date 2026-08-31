#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1431. 拥有最多糖果的孩子
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;
        int max = 0;
        for(int i = 0; i < candies.size(); i++) {
            if (candies[i] > max) max = candies[i];
            candies[i] += extraCandies;
        }
        for(int i = 0; i < candies.size(); i++) {
            v.push_back(candies[i] >= max);
        }
        return v;
    }
};

int main() {


    return 0;
}