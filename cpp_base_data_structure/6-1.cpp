#include <iostream>
using namespace std;

/*
    栈 顺序表实现
*/

template<typename T>
class Stack {
    private:
        T* data;
        int size;
        int capacity;
        void resize();

    public:
        Stack(): data(new T[10]), size(0), capacity(10) {}
        ~Stack();
        void push(T value);
        T pop();
        T top() const;
        bool isEmpty() const;
        int getSize() const;
};

template<typename T>
void Stack<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for(int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template<typename T>
void Stack<T>::push(T value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template<typename T>
T Stack<T>::pop() {
    if(size == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[--size];
}

template<typename T>
T Stack<T>::top() const {
    if(size == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[size - 1];
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
int Stack<T>::getSize() const {
    return size;
}

int main() {
    Stack<int> st;
    st.push(520);
    cout << st.top() << endl;
    st.push(1314);
    cout << st.top() << endl;
    st.push(999);
    cout << st.top() << endl;

    int val = st.pop();
    cout << "pop element: " << val << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getSize() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}