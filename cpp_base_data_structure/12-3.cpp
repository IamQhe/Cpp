#include <iostream>
using namespace std;

/*
    二叉搜索树
*/

template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(NULL), right(NULL) {
    }
    TreeNode(T x)
        : val(x), left(NULL), right(NULL) {
    }
};

template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;

    TreeNode<T>* insertNode(TreeNode<T>* node, T val);
    TreeNode<T>* removeNode(TreeNode<T>* node, T val);
    bool searchNode(TreeNode<T>* node, T val);
    void inOrder(TreeNode<T>* node);

public:
    BinarySearchTree()
        : root(NULL) {
    }
    ~BinarySearchTree();
    void insert(T val);
    void remove(T val);
    bool search(T val);
    void inOrderTraverial();
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    while (root) {
        remove(root->val);
    }
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::insertNode(TreeNode<T>* node, T val) {
    if (node == NULL) {
        return new TreeNode(val);
    }

    if (val < node->val) {
        node->left = insertNode(node->left, val);
    } else if (val > node->val ) {
        node->right = insertNode(node->right, val);
    }
    return node;
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::removeNode(TreeNode<T>* node, T val) {
    if (node == NULL) return NULL;

    if (val < node->val) {
        node->left = removeNode(node->left, val);
    } else if (val > node->val) {
        node->right = removeNode(node->right, val);
    } else {
        // 1. 左右子树均为空
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        } else if (node->right == NULL) {
            // 右子树为空
            TreeNode<T>* leftChild = node->left;
            delete node;
            return leftChild;
        } else if (node->left == NULL) {
            // 左子树为空
            TreeNode<T>* rightChild = node->right;
            delete node;
            return rightChild;
        } else {
            // 左右子树均不为空
            TreeNode<T>* tmpNode = node->right;
            while(tmpNode->left) {
                tmpNode = tmpNode->left;
            }
            node->val = tmpNode->val;
            node->right = removeNode(node->right, tmpNode->val);
        }
    }
    return node;
}

template <typename T>
bool BinarySearchTree<T>::searchNode(TreeNode<T>* node, T val) {
    if (node == NULL) return false;
    if (val < node->val ) {
        return searchNode(node->left, val);
    } else if (val > node->val) {
        return searchNode(node->right, val);
    }
    return true;
}

template <typename T>
void BinarySearchTree<T>::inOrder(TreeNode<T>* node) {
    if(node) {
        inOrder(node->left);
        cout << node->val << ' ';
        inOrder(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::insert(T val) {
    root = insertNode(root, val);
}

template <typename T>
void BinarySearchTree<T>::remove(T val) {
    root = removeNode(root, val);
}

template <typename T>
bool BinarySearchTree<T>::search(T val) {
    return searchNode(root, val);
}

template <typename T>
void BinarySearchTree<T>::inOrderTraverial() {
    inOrder(root);
    cout << endl;
}

int main() {
    BinarySearchTree<int> tree;
    tree.insert(70);
    tree.insert(90);
    tree.insert(80);
    tree.insert(95);
    tree.insert(100);
    tree.insert(60);
    tree.insert(50);

    tree.inOrderTraverial();

    tree.remove(95);
    tree.inOrderTraverial();

    tree.insert(75);
    tree.insert(85);
    tree.inOrderTraverial();

    return 0;
}