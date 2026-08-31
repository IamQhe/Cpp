#include <iostream>
using namespace std;

/*
    LeetCode 1678. 设计 Goal 解析器
*/

class Solution {
public:
    string interpret(string command) {
        string ret = "";
        int i = 0;
        while (i < command.size()) {
            if (command[i] == '(') {
                if (command[i+1] == ')') {
                    ret += 'o';
                    i += 2;
                } else {
                    ret += "al";
                    i += 4; 
                }
            } else {
                ret += 'G';
                i++;
            }
        }
        return ret;
    }
};

int main() {


    return 0;
}