#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
    HDOJ 2025 查找最大元素
*/

int main() {
    string s;
    while(cin >> s) {
        string ret = "";
        char max = 0;
        for(int i = 0; i < s.size(); i++) {
            max = s[i] > max ? s[i] : max;
        }
        for(int i = 0; i < s.size(); i++) {
            ret += s[i];
            if (s[i] == max) {
                ret += "(max)";
            }
        }
        cout << ret << endl;
    }

    return 0;
}