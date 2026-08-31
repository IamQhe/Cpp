#include <iostream>
using namespace std;

#define eleType double

/*
    4.1 顺序表

    操作：
        1. 排序
        2. 新增
        3. 删除
        4. 查找
*/

struct SequentialList {
    eleType* elements;
    int size;
    int capacity;
};

void initializeList(SequentialList* list, int capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("invalid capacity");
    }
    list->elements = new eleType[capacity];
    list->size = 0;
    list->capacity = capacity;
}

void destoryList(SequentialList* list) {
    delete[] list->elements;
    list->elements = NULL;
    list->capacity = 0;
    list->size = 0;
}

int size(SequentialList* list) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    return list->size;
}

bool isEmpty(SequentialList* list) {
    if (list->elements == NULL) return true;
    return list->size == 0;
}

void insert(SequentialList* list, int index, eleType value) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    if(index < 0 || index > list->size) {
        throw std::invalid_argument("invalid index");
    }
    if(list->size == list->capacity) {
        int newCapacity = list->capacity * 2;
        eleType* newElements = new eleType[newCapacity];
        for(int i = 0; i < list->size ; i++) {
            newElements[i] = list->elements[i];
        }
        delete[] list->elements;
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    for(int i = list->size ; i > index ; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = value;
    list->size++;
}

void deleteElement(SequentialList* list, int index) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    if(index < 0 || index >= list->size) {
        throw std::invalid_argument("invalid index");
    }
    for(int i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

int findElement(SequentialList* list, eleType value) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    for(int i = 0; i < list->size; i++) {
        if (list->elements[i] == value) return i;
    }
    return -1;
}

eleType getElement(SequentialList* list, int index) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("invalid index");
    }
    return list->elements[index];
}

void updateElement(SequentialList* list, int index, eleType value) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("invalid index");
    }
    list->elements[index] = value;
}

void printList(SequentialList* list) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    cout << "list size: " << size(list) << endl;
    for(int i = 0; i < list->size; i++) {
        cout << list->elements[i] << ' ';
    }
    cout << endl;
}

void clearList(SequentialList* list) {
    if (list->elements == NULL) throw std::invalid_argument("list is not initialized");
    list->size = 0;
}

int main() {
    int n;
    while(cin >> n) {
        if(!n) break;
        SequentialList s;
        initializeList(&s, 1);
        for(int i = 0; i < n; i++) {
            eleType x;
            cin >> x;
            insert(&s, i, x);
        }
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < size(&s); i++) {
            eleType value = getElement(&s, i);
            if(value > 1e-8) {
                c++;
            } else if (value < -1e-8) {
                a++;
            }else {
                b++;
            }
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}