#include <iostream>
using namespace std;

/**
 * 输入 
 *  第一行： n m    （n： 学生数量；m： 课程数量）
 *  第二行： 第一个学生的各科成绩
 *  ...
 *  第 n+1 行： 第 n 个学生的各科成绩
 *  
 * 
 * 输出：
 *  第一行： n 个学生的平均成绩
 *  第二行： 第 m 门课的平均成绩
 *  第三行： 大于第 m 门课平均成绩的学生数量
 */

 double s[1000][1000];

 double a[1000];
 double b[1000];
 int c = 0;

int main() {
    int n, m;
    double sum;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < m; j++) {
            cin >> s[i][j];
            sum += s[i][j];
        }
        a[i] = sum / m;
    }

    for(int i = 0; i < m; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += s[j][i];
        }
        b[i] = sum / n;
    }

    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < m; j++) {
            if(s[i][j] < b[j]) flag = false;
        }
        if (flag) {
            c++;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    cout << endl;

    for(int i = 0; i < m; i++) {
        printf("%.2lf ", b[i]);
    }
    cout << endl;

    cout << c << endl;

    return 0;
}