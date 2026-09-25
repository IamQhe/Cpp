#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 1207. 独一无二的出现次数
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        unordered_map<int, bool> count;
        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i]]++;
        }

        for (auto i = hash.begin(); i != hash.end() ; i++) {
            if (count.find(i->second) != count.end()) {
                return false;
            }
            count[i->second] = true;
        }
        return true;
    }
};

int main() {
    
    return 0;
}