#include <iostream>
#include <cstring>
using namespace std;

/*
    HDOJ 2026 首字母变大写
*/

int main() {
    char s[110];
    while(gets(s)) {
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (i == 0 || (s[i-1] == ' ' && s[i] >= 'a')) {
                s[i] = s[i] - 'a' + 'A';
            }
        }
        cout << s << endl;
    }
    return 0;
}