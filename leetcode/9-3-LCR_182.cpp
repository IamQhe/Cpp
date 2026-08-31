#include <iostream>
using namespace std;

/*
    LeetCode LCR 182. 动态口令
*/

class Solution {
public:
    string dynamicPassword(string password, int target) {
        string ret = "";
        for(int i = target; i < password.size(); i++) {
            ret += password[i];
        }
        for(int i = 0; i < target; i++) {
            ret += password[i];
        }
        return ret;
    }
};

int main() {


    return 0;
}