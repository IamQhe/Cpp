#include <iostream>
using namespace std;

/*
    HDOJ 2014 青年歌手大奖赛_评委会打分
*/

int main() {
    int n;
    while(cin >> n) {
        double min = 101, max = -1;
        double sum = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x < min) {
                min = x;
            }
            if(x > max) {
                max = x;
            }
            sum += x;
        }
        double ans = (sum - min - max) / (n - 2);
        printf_s("%.2lf\n", ans);
    }
    return 0;
}