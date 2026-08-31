#include <iostream>
using namespace std;

/*
    3.3 类内定义

    3.3.1 类内成员函数

    3.3.2 类外函数
        构造函数的类外实现
            1. 保留声明
            2. 拷贝声明
            3. 加作用域
            4. 拷贝实现
            5. 模板参数列表声明
            6. 指定模板类型
*/

template <class T> class DynamicArray {
    private:
        T* elements;
        int size;

    public:
        DynamicArray(int n);
        ~DynamicArray();
        T& operator[](int index);
        void update(int index, T value);    // 修改 index 索引的元素为 value
};

template <typename T> 
DynamicArray<T>::DynamicArray(int n) : size(n) {
    elements = new T[n];
}

template <typename T> 
DynamicArray<T>::~DynamicArray() {
    delete[] elements;
}

template <typename T> 
T& DynamicArray<T>::operator[](int index) {
    return elements[index];
}

template <typename T> 
void DynamicArray<T>::update(int index, T value) {
    elements[index] = value;
}

int main() {
    DynamicArray<int> intArr(10);
    intArr[0] = 1;
    intArr[1] = 2;
    intArr.update(2, 3);
    cout << intArr[0] << " " << intArr[1] << " " << intArr[2] << endl;

    return 0;
}