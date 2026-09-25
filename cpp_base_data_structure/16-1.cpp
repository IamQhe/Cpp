#include <iostream>
using namespace std;

/*
    哈希表：
        常见哈希函数：
            1. 直接取址法
            2. 平方取中法
            3. 折叠法
            4. 除留余数法
            5. 位与法

        哈希冲突：
            1. 开放定址法
            2. 链地址法
*/

template<typename KeyType, typename ValueType>
class HashNode {
    public:
        KeyType key;
        ValueType value;
        HashNode<KeyType, ValueType>* next;

        HashNode(KeyType k, ValueType v): key(k), value(v), next(NULL) {}
};

template<typename KeyType, typename ValueType>
class HashTable {
    private:
        int size;
        HashNode<KeyType, ValueType>** table;

        int hash(const KeyType& key) const {
            int index = key % size;
            if (index < 0) {
                index += size;
            }
            return index;
        }

    public:
        HashTable(int size = 256);
        ~HashTable();
        void insert(const KeyType& key, const ValueType value);
        void remove(const KeyType& key);
        bool find(const KeyType& key, ValueType& value) const;
};

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(int size) {
    this->size = size;
    table = new HashNode<KeyType, ValueType>*[size];
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable() {
    for(int i = 0; i < size; i++) {
        if (table[i]) {
            HashNode<KeyType, ValueType>* curr = table[i];
            while(curr) {
                HashNode<KeyType, ValueType>* tmp = curr;
                curr = curr->next;
                delete tmp;
            } 
        }
        table[i] = NULL;
    }
    delete table;
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType value) {
    int index = hash(key);
    HashNode<KeyType, ValueType>* node = new HashNode(key, value);
    if (!table[index]) {
        table[index] = node;
    } else {
        node->next = table[index];
        table[index] = node;
    }
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key) {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key == key) {
            HashNode<KeyType, ValueType>* next = table[index]->next;
            delete table[index];
            table[index] = next;
        } else {
            HashNode<KeyType, ValueType>* curr = table[index];
            while(curr->next && curr->next->key != key) {
                curr = curr->next;
            }
            if (curr->next) {
                HashNode<KeyType, ValueType>* next = curr->next->next;
                delete curr->next;
                curr->next = next;
            }
        }
    }
}

template<typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::find(const KeyType& key, ValueType& value) const {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key == key) {
            value = table[index]->value;
            return true;
        } else {
            HashNode<KeyType, ValueType>* curr = table[index];
            while(curr->next && curr->next->key != key) {
                curr = curr->next;
            }
            if (curr->next) {
                value = curr->next->value;
                return true;
            }
        }
    }
    return false;
}

template<typename KeyType>
class HashCounter {
    private:
        int* counter;
        int counterIndex;
        int counterSize;
        HashTable<KeyType, int>* hash;

    public:
        HashCounter(int size = 256);
        ~HashCounter();
        void reset();
        int add(const KeyType& key);
        int sub(const KeyType& key);
        int get(const KeyType& key) const;
};

template<typename KeyType>
HashCounter<KeyType>::HashCounter(int size) {
    counterSize = size;
    counterIndex = 0;
    counter = new int[counterSize];
    hash = NULL;
    reset();
}

template<typename KeyType>
HashCounter<KeyType>::~HashCounter() {
    delete[] counter;
    if (hash) {
        delete hash;
        hash = NULL;
    }
}

template<typename KeyType>
void HashCounter<KeyType>::reset() {
    if (hash) {
        delete hash;
        hash = NULL;
    }
    hash = new HashTable<KeyType, int>(counterSize);
    counterIndex = 0;
    for (int i = 0; i < counterSize; i++) {
        counter[i] = 0;
    }
}

template<typename KeyType>
int HashCounter<KeyType>::add(const KeyType& key) {
    int idx;
    if (!hash->find(key, idx)) {
        idx = counterIndex++;
        hash->insert(key, idx);
    }
    return ++counter[idx];
}

template<typename KeyType>
int HashCounter<KeyType>::sub(const KeyType& key) {
    int idx;
    if (hash->find(key, idx)) {
        return --counter[idx];
    }
    return 0;
}

template<typename KeyType>
int HashCounter<KeyType>::get(const KeyType& key) const {
    int idx;
    if (hash->find(key, idx)) {
        return counter[idx];
    }
    return 0;
}

int main() {
    HashTable<int, char> h(100);
    h.insert(1, 'a');
    h.insert(2, 'b');
    h.insert(3, 'c');
    h.insert(10086, 'd');

    char val;
    if (!h.find(33, val)) {
        cout << "33 not found" << endl;
    }
    if (h.find(10086, val)) {
        cout << "key 10086: " << val << endl;
    }

    // HashCounter
    HashCounter<long long> hc(256);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    hc.add(14);
    cout << "14 counter: " << hc.get(14);
    return 0;
}