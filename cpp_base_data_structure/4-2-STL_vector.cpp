#include <iostream>
#include <vector>
using namespace std;

/*
    4.2 C++ 顺序表： vector 模板类

    接口:
        - push_back(v)
        - pop_back()
        - size()
*/

int main() {
    // 初始化
    // vector<int> ret;
    vector<int> ret = {1, 2, 3, 4, 5};

    // 元素索引
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
    cout << endl;
    cout << ret.size() << endl;

    // 插入
    ret.push_back(1024);
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
    cout << endl;
    cout << ret.size() << endl;

    // 删除在顺序表中比较耗时，一般需要删除的不用 vector 

    return 0;
}