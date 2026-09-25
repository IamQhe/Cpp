#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode LCR 173. 点名
*/

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        unordered_map<int, bool> hash;
        for(int i = 0; i < records.size(); i++) {
            hash[records[i]] = true;
        }

        for(int i = 0; ; i++) {
            if (hash.find(i) == hash.end()) return i;
        }
        return 0;
    }
};

int main() {
    
    return 0;
}