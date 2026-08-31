#include <iostream>
using namespace std;

/*
    LeetCode 1812. 判断国际象棋棋盘中一个格子的颜色
*/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char a = coordinates[0] - 'a';
        char b = coordinates[1];
        return (a + b) % 2 == 0;
    }
};

int main() {


    return 0;
}