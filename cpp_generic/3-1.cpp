#include <iostream>
using namespace std;

/*
    3. 类模板

    3.1 动态数组类
        定义静态数组时，数组大小必须是常量

*/

class DynamicArray {
    public:
        DynamicArray(int n):size(n) {
            elements = new int[n];
        }

        ~DynamicArray() {
            delete[] elements;
        }

        // 返回值需要引用形式，否则不能对其进行赋值修改
        int& operator[](int index) {
            return elements[index];
        }

    private:
        int* elements;
        int size;
};

int main() {
    int n = 10;
    // int a[n];    标准 C++ 不能这样定义

    // 动态数组
    int* ptr = new int[n];

    // 动态数组类
    // 对上面指针进行封装，使其成为一个成员变量
    DynamicArray da(100);
    da[1] = 3;
    da[9] = 4;
    cout << da[0] << " " << da[1] << endl;  
    return 0;
}