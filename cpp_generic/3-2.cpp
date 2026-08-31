#include <iostream>
using namespace std;

/*
    3.2 类模板
*/

// 或 template<typename T>
template<class T>
class DynamicArray {
    public:
        DynamicArray(int n):size(n) {
            elements = new T[n];
        }

        ~DynamicArray() {
            delete[] elements;
        }

        T& operator[](int index) {
            return elements[index];
        }

    private:
        T* elements;
        int size;
};

int main() {
    DynamicArray<int> intArr(10);
    intArr[0] = 1;
    intArr[1] = 2;
    cout << intArr[0] << " " << intArr[1] << " " << intArr[2] << endl;

    DynamicArray<double> doubleArr(10);
    doubleArr[0] = 1.0;
    doubleArr[1] = 2.1;
    cout << doubleArr[0] << " " << doubleArr[1] << " " << doubleArr[2] << endl;

    return 0;
}