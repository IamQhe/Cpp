#include <iostream>
using namespace std;

/*
    树
*/
template<typename T>
struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(T data): data(data), next(NULL) {}
};


template<typename T>
struct TreeNode {
    T data;
    ListNode<TreeNode<T>*>* childrenHead;

    TreeNode():childrenHead(NULL) {}

    void AddChildren(TreeNode<T>* node) {
        ListNode<TreeNode<T>*>* childNode = new ListNode<TreeNode<T>*>(node);
        if (childrenHead == NULL) {
            childrenHead = childNode;
        } else {
            childNode->next = childrenHead;
            childrenHead = childNode;
        }
    }
};

template<typename T>
class Tree {
    private:
        TreeNode<T>* nodes;
        TreeNode<T>* root;

    public:
        Tree();
        Tree(int maxNodes);
        ~Tree();
        TreeNode<T>* GetTreeNode(int nodeId);
        void SetRoot(int rootId);
        void AddChildren(int parentId, int childId);
        void AssignData(int nodeId, T data);
        void Print(TreeNode<T>* node = NULL);
};

template<typename T>
Tree<T>::Tree() {
    nodes = new TreeNode<T>[10];
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
    nodes = new TreeNode<T>[maxNodes];
}

template<typename T>
Tree<T>::~Tree() {
    delete[] nodes;
}

template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int nodeId) {
    return &nodes[nodeId];
}

template<typename T>
void Tree<T>::SetRoot(int rootId) {
    root = GetTreeNode(rootId);
}

template<typename T>
void Tree<T>::AddChildren(int parentId, int childId) {
    TreeNode<T>* parentNode = GetTreeNode(parentId);
    TreeNode<T>* childNode = GetTreeNode(childId);
    parentNode->AddChildren(childNode);
}

template<typename T>
void Tree<T>::AssignData(int nodeId, T data) {
    GetTreeNode(nodeId)->data = data;
}

template<typename T>
void Tree<T>::Print(TreeNode<T>* node) {
    if (node == NULL) {
        node = root;
    }
    cout << node->data << ' ';
    ListNode<TreeNode<T>*>* tmp = node->childrenHead;
    while(tmp) {
        Print(tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Tree<char> t(9);

    t.AssignData(0, 'a');
    t.AssignData(1, 'b');
    t.AssignData(2, 'c');
    t.AssignData(3, 'd');
    t.AssignData(4, 'e');
    t.AssignData(5, 'f');
    t.AssignData(6, 'g');
    t.AssignData(7, 'h');
    t.AssignData(8, 'i');

    t.AddChildren(0, 2);
    t.AddChildren(0, 1);
    t.AddChildren(2, 6);
    t.AddChildren(2, 5);
    t.AddChildren(1, 4);
    t.AddChildren(1, 3);
    t.AddChildren(3, 8);
    t.AddChildren(3, 7);

    t.SetRoot(0);

    t.Print();

    return 0;
}