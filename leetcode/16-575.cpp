#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 575. 分糖果
*/

class Solution1 {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, bool> hash;
        int n = candyType.size();
        int count = 0;
        for (int i = 0; i < n && count < (n / 2) ; i++) {
            if (hash.find(candyType[i]) == hash.end()) {
                count++;
                hash[candyType[i]] = true;
            }
        }
        return count;
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < candyType.size() ; i++) {
            hash[candyType[i]] = true;
        }
        return min(hash.size(), candyType.size() / 2);
    }
};

int main() {
    
    return 0;
}