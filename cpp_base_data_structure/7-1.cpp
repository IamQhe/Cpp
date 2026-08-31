#include <iostream>
using namespace std;

/*
    队列： 顺序表实现
*/

template<typename T>
class Queue {
    private:
        T* data;
        int front;
        int rear;
        int capacity;

        void resize();

    public:
        Queue():data(new T[10]), front(0), rear(0), capacity(10) {}
        ~Queue();
        void enqueue(T element);
        T dequeue();
        T getFront() const;
        int getSize() const;
};

template<typename T>
void Queue<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for(int i = 0; i < rear; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity *= 2;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
void Queue<T>::enqueue(T element) {
    if (rear == capacity) {
        resize();
    }
    data[rear++] = element;
}

template<typename T>
T Queue<T>::dequeue() {
    if (rear == front) {
        throw std::overflow_error("queue is empty");
    }
    return data[front++];
}

template<typename T>
T Queue<T>::getFront() const {
    if (rear == front) {
        throw std::overflow_error("queue is empty");
    }
    return data[front];
}

template<typename T>
int Queue<T>::getSize() const {
    return rear - front;
}

int main() {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(8);

    cout << "queue size: " << q.getSize() << endl;
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    cout << "queue size: " << q.getSize() << endl;

    q.enqueue(2);
    q.enqueue(3);
    cout << "queue size: " << q.getSize() << endl;
    return 0;
}