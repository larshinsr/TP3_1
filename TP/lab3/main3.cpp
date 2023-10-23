#include "BinaryTree.t.h"
#include <iostream>



int main() {
    BinaryTree<int> tree;

    // Вставляем элементы в бинарное дерево
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9); 

    // Выводим дерево в порядке предварительного обхода
    std::cout << "Binary Tree in Preorder: ";
    tree.printPreOrder();
    std::cout << std::endl;

    // Вызываем новый метод для поиска поддеревьев
    int min_height = 2;
    int max_height = 3;
    std::vector<Subtree<int>> subtrees = tree.findSubtreesWithLeafHeightInRange(min_height, max_height);

    // Выводим найденные поддеревья
    std::cout << "Subtrees with leaf height in range [" << min_height << ", " << max_height << "]:\n";
    for (const Subtree<int>& subtree : subtrees) {
        std::cout << "Subtree Preorder: ";
        tree.printPreOrder();
        std::cout << std::endl;
    }

    return 0;
}
