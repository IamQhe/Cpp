#include <iostream>
using namespace std;

/*
    二叉树
*/

template<typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode():val(0), left(NULL), right(NULL) {}
    TreeNode(T data): val(data), left(NULL), right(NULL) {}
};

template<typename T>
class Tree {
    private:
        TreeNode<T>* nodes;
        TreeNode<T>* root;
        size_t nodesSize;

        TreeNode<T>* Create(T* a, int size, int nodeId, T nullNode);
        void visit(TreeNode<T>* node);
        void preOrder(TreeNode<T>* node);
        void inOrder(TreeNode<T>* node);
        void postOrder(TreeNode<T>* node);

    public:
        Tree();
        Tree(int maxSize);
        ~Tree();
        TreeNode<T>* GetTreeNode(int nodeId);
        void CreateTree(T* a, int size, T nullNode);
        void preOrderTraverse();
        void inOrderTraverse();
        void postOrderTraverse();
};

template<typename T>
Tree<T>::Tree() {
    nodesSize = 20;
    nodes = new TreeNode<T>[nodesSize];
}

template<typename T>
Tree<T>::Tree(int maxSize) {
    nodesSize = maxSize;
    nodes = new TreeNode<T>[nodesSize];
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
void Tree<T>::CreateTree(T* a, int size, T nullNode) {
    root = Create(a, size, 1, nullNode);
}

template<typename T>
TreeNode<T>* Tree<T>::Create(T* a, int size, int nodeId, T nullNode) {
    if (nodeId >= size || a[nodeId] == nullNode) return NULL;
    TreeNode<T>* node = GetTreeNode(nodeId);
    node->val = a[nodeId];
    node->left = Create(a, size, nodeId * 2, nullNode);
    node->right = Create(a, size, nodeId * 2 + 1, nullNode);
    return node;
}

template<typename T>
void Tree<T>::visit(TreeNode<T>* node) {
    cout << node->val << ' ';
}

template<typename T>
void Tree<T>::preOrder(TreeNode<T>* node) {
    if (node) {
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

template<typename T>
void Tree<T>::inOrder(TreeNode<T>* node) {
    if (node) {
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

template<typename T>
void Tree<T>::postOrder(TreeNode<T>* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

template<typename T>
void Tree<T>::preOrderTraverse() {
    preOrder(root);
    cout << endl;
}

template<typename T>
void Tree<T>::inOrderTraverse() {
    inOrder(root);
    cout << endl;
}
template<typename T>
void Tree<T>::postOrderTraverse() {
    postOrder(root);
    cout << endl;
}

int main() {
    char nullNode = '-';
    char a[] = {
        nullNode, 'a', 'b', 'c', 'd',
        nullNode, 'e', 'f', 'g', 'h',
        nullNode, nullNode, nullNode, nullNode, 'i' 
    };

    Tree<char> t(15);
    t.CreateTree(a, 15, nullNode);
    t.preOrderTraverse();
    t.inOrderTraverse();
    t.postOrderTraverse();

    return 0;
}