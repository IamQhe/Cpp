#include <iostream>
using namespace std;

/*
    HDOJ 2041 超级楼梯
*/

#define eleType int

struct ListNode {
    ListNode* next;
    eleType data;

    ListNode(eleType value):data(value),next(NULL) {}
};

class LinkedList {
    private:
        ListNode* head;
        int size;
    
    public:
        LinkedList():head(NULL), size(0){}
        ~LinkedList();

        void insert(int index, eleType value);
        void remove(int index);
        ListNode* get(int index);
        ListNode* find(eleType value);
        void update(int index, eleType value);
        void print();
        void append(eleType value);
        void ascInsert(eleType value);
        eleType sum();
};

LinkedList::~LinkedList() {
    ListNode* cur = head;
    while(cur) {
        ListNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

void LinkedList::insert(int index, eleType value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("invalid index");
    }
    ListNode* tmp = new ListNode(value);
    if(index == 0) {
        head = tmp;
    } else {
        ListNode* cur = head;
        for(int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
    }
    size++;
}

void LinkedList::remove(int index){
    if (index < 0 || index >= size) {
        throw std::out_of_range("invalid index");
    }
    if(index == 0) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    } else {
        ListNode* cur = head;
        for(int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    size--;
}

ListNode* LinkedList::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("invalid index");
    }
    ListNode* cur = head;
    for(int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur;
}

ListNode* LinkedList::find(eleType value){
    ListNode* cur = head;
    while(cur) {
        if(cur->data == value) {
            break;
        }
        cur = cur->next;
    }
    return cur;
}

void LinkedList::update(int index, eleType value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("invalid index");
    }
    ListNode* cur = get(index);
    cur->data = value;
}

void LinkedList::append(eleType value) {
    insert(size, value);
}

void LinkedList::ascInsert(eleType value) {
    if(size == 0) {
        insert(0, value);
        return;
    }
    ListNode* cur = head;
    for(int i = 0; i < size; i++) {
        if(value <= cur->data) {
            insert(i, value);
            return;
        }
        cur = cur->next;
    }
    insert(size, value);
}

void LinkedList::print() {
    ListNode* cur = head;
    cout << "LinkedList size: " << size << endl;
    for(int i = 0; i < size; i++) {
        cout << cur->data << ' ';
        cur = cur->next;
    }
    cout << endl;
}

eleType LinkedList::sum() {
    eleType sum = 0;
    ListNode* cur = head;
    for(int i = 0; i < size; i++) {
        sum += cur->data;
        cur = cur->next;
    }
    return sum;
}

int main() {
    LinkedList l;
    l.append(1);
    l.append(1);
    l.append(1);
    for(int i = 3; i <= 40; i++) {
        l.append(l.get(i-1)->data + l.get(i-2)->data);
    }

    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cout << l.get(x)->data << endl;
    }
    return 0;
}