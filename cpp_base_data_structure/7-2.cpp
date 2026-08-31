#include <iostream>
using namespace std;

/*
    队列： 链表实现
*/

template<typename T>
class Queue {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T val): data(val), next(NULL) {}
        };

        Node* front;
        Node* rear;
        int size;

    public:
        Queue(): front(NULL), rear(NULL), size(0) {}
        ~Queue();
        void enqueue(T element);
        T dequeue();
        T getFront() const;
        int getSize() const;
};

template<typename T>
Queue<T>::~Queue() {
    while(front) {
        Node* tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<typename T>
void Queue<T>::enqueue(T element) {
    if (rear == NULL) {
        rear = new Node(element);
        front = rear;
    } else {
        rear->next = new Node(element);
        rear = rear->next;
    }
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (front == NULL) {
        throw std::underflow_error("Queue is empty");
    }
    T element = front->data;
    Node* tmp = front;
    front = front->next;
    delete tmp;
    size--;
    if (size == 0) rear = NULL;
    return element;
}

template<typename T>
T Queue<T>::getFront() const {
    if (front == NULL) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template<typename T>
int Queue<T>::getSize() const {
    return size;
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
    q.enqueue(4);
    cout << "queue size: " << q.getSize() << endl;
    return 0;
}