#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 2011. 执行操作后的变量值
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(int i = 0; i < operations.size(); i++) {
            string command = operations[i];
            if (command == "--X" || command == "X--") {
                --x;
            } else if (command == "X++" || command == "++X") {
                x++;
            }
        }
        return x;
    }
};

int main() {


    return 0;
}