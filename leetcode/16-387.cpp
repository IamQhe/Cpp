#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    LeetCode 387. 字符串中的第一个唯一字符
*/

class Solution1 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, bool> hash;
        for (int i = 0 ; i < s.size(); i++) {
            if (hash.find(s[i]) != hash.end()) continue;
            hash[s[i]] = true; 
            int flag = true;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == s[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[256];
        for (int i = 0; i < s.size(); i++) {
            arr[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}