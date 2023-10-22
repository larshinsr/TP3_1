#pragma once
#include <iostream>
template<typename T>
class DynamicArray
{
private:
    struct Node
    {
        T data;
        Node* nextNode = nullptr;
    }*First = nullptr;
public:
    int numRows = 0;
    int numColumns = 0;
    int size()
    {
        if (First == nullptr)
        {
            return 0;
        }
        int countOfNodes = 0;
        Node* tmp = First;
        while (tmp != nullptr)
        {
            countOfNodes++;
            tmp = tmp->nextNode;
        }
        return countOfNodes;
    }
    //----------------------------------------------------------------------------------------------------
    void print()
    {
        Node* tmp = First;
        int i = 0;
        while (tmp != nullptr)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->nextNode;
            i++;
            if (i == numColumns)
            {
                std::cout << std::endl;
                i = 0;
            }
        }
        std::cout << std::endl;
    }
    //----------------------------------------------------------------------------------------------------
    void push(T value)
    {
        if (First == nullptr)
        {
            // Если список пуст, создаем первый узел
            First = new Node;
            First->data = value;
            return;
        }
        Node* tmp = First;
        while (tmp->nextNode != nullptr)
        {
            tmp = tmp->nextNode;
        }
        // Добавляем новый узел в конец списка
        tmp->nextNode = new Node;
        tmp = tmp->nextNode;
        tmp->data = value;
    }
    //----------------------------------------------------------------------------------------------------
    T at(int index)
    {
        int iterations = index;
        Node* tmp = First;
        if (tmp == nullptr)
        {
            throw std::string("Holy");
        }
        while (iterations > 0 && tmp != nullptr)
        {
            iterations--;
            tmp = tmp->nextNode;
        }
        return tmp->data;
    }
    //----------------------------------------------------------------------------------------------------
    void setValue(int index, T value)
    {
        int iterations = index;
        Node* tmp = First;
        if (tmp == nullptr)
        {
            throw std::string("Holy");
        }
        while (iterations > 0)
        {
            iterations--;
            tmp = tmp->nextNode;
        }
        tmp->data = value;
    }
};