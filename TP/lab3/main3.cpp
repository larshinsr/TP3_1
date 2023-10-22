#include "BinaryTree.h"
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

    std::cout << "Дерево в порядке предварительного обхода: ";
    tree.printPreOrder();  // Вывод в порядке предварительного обхода

    // Проверяем поиск элементов
    int valueToFind = 3;
    if (tree.search(valueToFind)) {
        std::cout << valueToFind << " найден в дереве." << std::endl;
    } else {
        std::cout << valueToFind << " не найден в дереве." << std::endl;
    }

    // Удаляем элемент
    int valueToRemove = 5;
    tree.remove(valueToRemove);

    std::cout << "Дерево после удаления " << valueToRemove << ": ";
    tree.printPreOrder();

    return 0;
}
