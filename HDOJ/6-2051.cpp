#include <iostream>
using namespace std;

/*
    HDOJ 2051 Bitset
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
    int n;
    while(cin >> n) {
        Stack<int> st;
        while(n) {
            st.push(n & 1);
            n >>= 1;
        }
        while(st.getSize()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }

    return 0;
}