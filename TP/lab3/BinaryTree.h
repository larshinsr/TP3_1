#pragma once

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
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

   private:
    Node<T>* root;

   
    void destroyTree(Node<T>* node);
    void insert(Node<T>*& node, const T& value);
    bool search(Node<T>* node, const T& value);
    void remove(Node<T>*& node, const T& value);
    void printPreOrder(Node<T>* node);
};


