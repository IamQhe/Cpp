#include <iostream>
using namespace std;

/*
    栈 链表实现
*/

template<typename T>
class Stack {
    private:
        struct ListNode {
            T data;
            ListNode* next;

            ListNode(T val): data(val), next(NULL) {}
        };
        int size;
        ListNode* head;

    public:
        Stack():size(0), head(NULL) {}
        ~Stack();
    
        void push(T data);
        T pop();
        T top() const;
        int getSize() const;
};

template<typename T>
Stack<T>::~Stack() {
    while(head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T>
void Stack<T>::push(T data) {
    ListNode* newHead = new ListNode(data);
    newHead->next = head;
    head = newHead;
    size++;
}

template<typename T>
T Stack<T>::pop() {
    if (head == NULL) {
        throw std::underflow_error("Stack is empty");
    }
    T element = head->data;
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    size--;
    return element;
}

template<typename T>
T Stack<T>::top() const {
    if (head == NULL) {
        throw std::underflow_error("Stack is empty");
    }
    return head->data;
}

template<typename T>
int Stack<T>::getSize() const {
    return size;
}


int main() {
    Stack<int> s;
    s.push(4);
    s.push(7);
    s.push(13);
    cout << "stack size: " << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << "stack size: " << s.getSize() << endl;

    return 0;
}