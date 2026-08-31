#include <iostream>
using namespace std;

/*
    HDOJ 1276 士兵队列训练问题
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
        throw std::overflow_error("Queue is empty");
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
        throw std::overflow_error("Queue is empty");
    }
    return front->data;
}

template<typename T>
int Queue<T>::getSize() const {
    return size;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        Queue<int> q1;
        Queue<int> q2;

        int x;
        cin >> x;
        for(int i = 1; i <= x; i++) {
            q1.enqueue(i);
        }

        while(q1.getSize() > 3) {
            int cnt = 0;
            while(q1.getSize()) {
                int ele = q1.dequeue();
                cnt++;
                if (cnt % 2 == 1) {
                    q2.enqueue(ele);
                }
            }

            if (q2.getSize() <= 3) break;
            cnt = 0;
            while(q2.getSize()) {
                int ele = q2.dequeue();
                cnt++;
                if (cnt % 3 == 1 || cnt % 3 == 2) {
                    q1.enqueue(ele);
                }
            }
        }

        while(q1.getSize()) {
            cout << q1.dequeue() << ' ';
        }
        while(q2.getSize()) {
            cout << q2.dequeue() << ' ';
        }
        cout << endl;
    }

    return 0;
}