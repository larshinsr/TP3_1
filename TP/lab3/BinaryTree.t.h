#pragma once
#include<iostream>
#include<vector>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
struct Subtree {
    Node<T>* root;
    Subtree(Node<T>* node) : root(node) {}
};

template <typename T>
class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();

    void insert(const T& value);
    bool search(const T& value);
    void remove(const T& value);
    void printPreOrder();
    std::vector<Subtree<T>> findSubtreesWithLeafHeightInRange(int min_height, int max_height);
   private:
    Node<T>* root;
    struct Subtree {
        Node<T>* root;
        Subtree(Node<T>* node) : root(node) {}
    };

    void findSubtreesWithLeafHeightInRange(Node<T>* node, int current_height, int min_height, int max_height, std::vector<Subtree<T>>& result);
    void destroyTree(Node<T>* node);
    void insert(Node<T>*& node, const T& value);
    bool search(Node<T>* node, const T& value);
    void remove(Node<T>*& node, const T& value);
    void printPreOrder(Node<T>* node);
};

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroyTree(root);
}
 
template <typename T>
void BinaryTree<T>::destroyTree(Node<T>* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

template <typename T>
void BinaryTree<T>::insert(const T& value) {
    insert(root, value);
}

template <typename T>
void BinaryTree<T>::insert(Node<T>*& node, const T& value) {
    if (!node) {
        node = new Node<T>(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

template <typename T>
bool BinaryTree<T>::search(const T& value) {
    return search(root, value);
}

template <typename T>
bool BinaryTree<T>::search(Node<T>* node, const T& value) {
    if (!node) {
        return false;
    } else if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

template <typename T>
void BinaryTree<T>::remove(const T& value) {
    remove(root, value);
}

template <typename T>
void BinaryTree<T>::remove(Node<T>*& node, const T& value) {
    if (!node) {
        return;
    } else if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if (!node->left) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node<T>* minNode = node->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            node->data = minNode->data;
            remove(node->right, minNode->data);
        }
    }
}

template <typename T>
void BinaryTree<T>::printPreOrder() {
    printPreOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPreOrder(Node<T>* node) {
    if (node) {
        std::cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

template<typename T>
std::vector<Subtree<T>> findSubtreesWithLeafHeightInRange(int min_height, int max_height) {
    std::vector<Subtree<T>> result;
    findSubtreesWithLeafHeightInRange(root, min_height, max_height, result);
    return result;
}
template<typename T>
void findSubtreesWithLeafHeightInRange(Node<T>* node, int current_height, int min_height, int max_height, std::vector<Subtree<T>>& result) {
    if (node == nullptr) {
        return;
    }

    // Проверяем, является ли узел листом и его высота в заданном диапазоне
    if (node->left == nullptr && node->right == nullptr && current_height >= min_height && current_height <= max_height) {
        Subtree<T> subtree(node);
        result.push_back(subtree);
    }
    // Рекурсивно переходим к левому и правому поддереву
    findSubtreesWithLeafHeightInRange(node->left, current_height + 1, min_height, max_height, result);
    findSubtreesWithLeafHeightInRange(node->right, current_height + 1, min_height, max_height, result);
}