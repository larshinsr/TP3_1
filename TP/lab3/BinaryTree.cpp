#include "BinaryTree.h"
#include <iostream>

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

