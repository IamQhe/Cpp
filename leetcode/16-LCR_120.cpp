#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode LCR 120. 寻找文件副本
*/

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_map<int, bool> hash;

        for (int i = 0; i < documents.size(); i++) {=
            if (hash.find(documents[i]) != hash.end()) {
                hash[doc] = true;
            }
            hash[documents[i]] = true;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}