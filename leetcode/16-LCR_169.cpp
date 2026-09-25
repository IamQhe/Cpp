#include <iostream>
using namespace std;

/*
    LeetCode LCR 169. 招式拆解 II
*/

class Solution {
public:
    char dismantlingAction(string arr) {
        int n[256] = {0};
        for (int i = 0; i < arr.size(); i++) {
            n[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (n[arr[i]] == 1) return arr[i];
        }
        return ' ';
    }
};

int main() {
    
    return 0;
}