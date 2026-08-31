#include <iostream>
using namespace std;

/*
    HDOJ 2081 手机短号   
*/

int main() {
    int n;
    cin >> n;
    char phone[12];

    while(n--){
        cin >> phone;
        cout << '6' << phone + 6 << endl;
    }
    
    return 0;
}

// 注意： 有些情况会使字符串末尾多一个 \0：
//      1. 双引号形式
//      2. 使用字符串输入函数读取时：例如 cin >> str; 或 cin.getline()。
//      3. 输入流会自动在尾部加 \0
//      4. 部分标准库函数处理结果：例如
//      strncpy，在源字符串长度小于指定大小时，会用 \0 填充剩余空间。