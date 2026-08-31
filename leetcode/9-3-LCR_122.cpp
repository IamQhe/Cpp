#include <iostream>
using namespace std;

/*
    LeetCode LCR 122. 路径加密
*/

class Solution {
public:
    string pathEncryption(string path) {
        for(int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                path[i] = ' ';
            }
        }
        return path;
    }
};

int main() {


    return 0;
}