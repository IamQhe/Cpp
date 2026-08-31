#include <iostream>
#include <cstring>
using namespace std;

/*
    HDOJ 2030 汉字统计
*/

int main() {
    char s[500];
    int n;
    cin >> n;
    getchar();
    while(n--) {
        gets(s);
        int cnt = 0;
        int len = strlen(s);
        // 汉字机内码特点： 
        //  1. 最高位是 1， 补码最高位为 1 表示负数
        //  2. 一个汉字占 2 个字符
        for(int i = 0; i < len; i++) {
            if (s[i] < 0) {
                cnt++;
            }
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}