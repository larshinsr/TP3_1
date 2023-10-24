#pragma once
#include <iostream>
class BinaryTree
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    } *root;
    void inorderRecursive(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderRecursive(root->right);
        inorderRecursive(root->left);
    }
    //-----------------------------------------------------------------------------------------
    void printHelper(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        int asd = node->data;
        std::cout << asd << std::endl;
        printHelper(node->left);
        printHelper(node->right);
    }
    //-----------------------------------------------------------------------------------------
    int subTreeRecursive(Node* node, int low, int high, unsigned int deep)
    {
        static int c = 0;
        if (deep > high || isLeaf(node) || node == nullptr)
        {
            return 0;
        }
        if (low <= deep && deep <= high)
        {
            if (isSubTree(node))
            {
                c++;
            }
        }
        subTreeRecursive(node->left, low, high, deep + 1);
        subTreeRecursive(node->right, low, high, deep + 1);
        return c;
    }
    //-----------------------------------------------------------------------------------------
    int numOfLeafRecursive(Node* node, int high)
    {
        static int c = 0;
        if (node == nullptr || high < 0)
        {
            return 0;
        }
        if (high >= 0 && isLeaf(node))
        {
            c++;
        }
        numOfLeafRecursive(node->left, high - 1);
        numOfLeafRecursive(node->right, high - 1);
        return c;
    }
    //-----------------------------------------------------------------------------------------
    Node* recurSiveInsert(Node* root, int value, Node* parent = nullptr) // Добавляем параметр parent
    {
        if (root == nullptr)
        {
            Node* newNode = new Node(value);
            return newNode;
        }
        if (value < root->data)
        {
            root->left = recurSiveInsert(root->left, value, root); // Передаем текущий узел как родителя
        }
        else if (value > root->data)
        {
            root->right = recurSiveInsert(root->right, value, root); // Передаем текущий узел как родителя
        }

        return root;
    }
    //-----------------------------------------------------------------------------------------
public:
    BinaryTree() : root(nullptr) {}
    void insert(int value)
    {
        root = recurSiveInsert(root, value);
    }
    //-----------------------------------------------------------------------------------------
    void inorderTraversal()
    {
        inorderRecursive(root);
    }
    //-----------------------------------------------------------------------------------------
    // Рекурсивный метод для нахождения поддеревьев в заданном диапазоне
    int subTree(int low, int high)
    {
        if (!(low < high))
        {
            throw std::string("incorrect input");
        }
        return subTreeRecursive(root, low, high, 0);
    }
    //-----------------------------------------------------------------------------------------
    int numOfLeaf(int high)
    {
        return numOfLeafRecursive(root, high);
    }
    //-----------------------------------------------------------------------------------------
    bool isLeaf(Node* node)
    {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
    //-----------------------------------------------------------------------------------------
    bool isSubTree(Node* node)
    {
        return node != nullptr && ((node->left != nullptr) || (node->right != nullptr));
    }
    //-----------------------------------------------------------------------------------------
    void printVer1()
    {
        printHelper(root);
    }
    //-----------------------------------------------------------------------------------------
    int Finallaba(int low, int high)
    {
        return laba(root, low, high, 0);
    }
    // deep типа диапазон (пометка для себя)
    int laba(Node* node, int low, int high, int deep)
    {
        static int subTrees = 0;
        if (deep > high || node == nullptr)
        {
            return 0;
        }
        if (low <= deep && deep < high)
        {
                if (isLeaf(node->left))
                {
                    //std::cout << node->left->data << std::endl;                    
                    subTrees += deep;
                }
                if (isLeaf(node->right))
                {
                    //std::cout << node->right->data << std::endl;
                    subTrees += deep;
                }
        }
        laba(node->left, low, high, deep + 1);
        laba(node->right, low, high, deep + 1);
        if (subTrees == 0)
        {
            return 1;
        }
        return subTrees;
    }
    //-----------------------------------------------------------------------------------------
    void print()
    {
        printWithIndent(root, 0);
    }
    //-----------------------------------------------------------------------------------------
    void printWithIndent(Node* node, int level) {
        if (node == nullptr) {
            return;
        }
        printWithIndent(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << node->data << std::endl;
        printWithIndent(node->left, level + 1);
    }
};