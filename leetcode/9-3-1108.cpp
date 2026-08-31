#include <iostream>
using namespace std;

/*
    LeetCode 1108. IP 地址无效化
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string ret = "";
        for(int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                ret += "[.]";
            } else {
                ret += address[i];
            }
        }
        return ret;
    }
};

int main() {


    return 0;
}