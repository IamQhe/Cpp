#include <iostream>
using namespace std;

/*
    HDOJ 2021 发工资喽:)
*/
int a[6] = {100, 50, 10, 5, 2, 1};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int sum = 0;
        while(n--) {
            int x;
            cin >> x;
            int i = 0;
            while(x) {
                sum += x / a[i];
                x %= a[i];
                i++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}