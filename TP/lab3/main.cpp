#include <iostream>
#include <fstream>
#include "BinaryTree.h"
//
#include "queue.h"
#include <random>
void autoInput();
void manualInput();
int generateRandomNumber(int, int);
void randomInput(int, int, int);
int main()
{
    int choice;
    while (true)
    {
        std::cout << "\nchose your input method:\n1. Input from files\n2. Manual input\n3. Random input\n4. Exit\nYour choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            autoInput();
        }
        else if (choice == 2)
        {
            manualInput();
        }
        else if (choice == 3)
        {
            int count = 0;
            int low = 0;
            int high = 0;
            while (count <= 0)
            {
                std::cout << "enter count of values: ";
                std::cin >> count;
            }
            std::cout << "enter a range of values (2 numbers): ";
            while (low == high || low > high || low < 0)
            {
                std::cout << "\nenter a range of values (2 numbers): ";
                std::cin >> low;
                std::cin >> high;
                if (low < high)
                {
                    break;
                }
            }
            randomInput(count, low, high);
            break;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "incorrect input\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}
//-----------------------------------------------------------------------------------------
void randomInput(int count, int low, int high)
{
    BinaryTree tree;
    int number;
    for (int i = 0; i < count; i++)
    {
        number = generateRandomNumber(low, high);
        std::cout << number << std::endl;
        tree.insert(number);
    }
    std::cout << "enter a range of Leafs (2 numbers): ";
    while (low == high || low > high || low < 0)
    {
        std::cout << "\nenter a range of values (2 numbers): ";
        std::cin >> low;
        std::cin >> high;
        if (low < high)
        {
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Otvet: " << tree.Finallaba(low, high) << "\nyour tree: ";
    std::cout << std::endl;
    tree.print();
}
//-----------------------------------------------------------------------------------------
void autoInput()
{
    BinaryTree tree;
    std::fstream inputFile("input.txt");
    int number;
    while (inputFile >> number)
    {
        tree.insert(number);
    }
    int low = 0, high = 0;
    while (low == high || low > high || low < 0)
    {
        std::cout << "\nenter a range of values (2 numbers): ";
        std::cin >> low;
        std::cin >> high;
        if (low < high)
        {
            break;
        }
        std::cout << "incorrect input\n\n";
    }
    std::cout << std::endl;
    std::cout << "Otvet: " << tree.Finallaba(low, high)<<"\nyour tree: ";
    std::cout << std::endl;
    tree.print();
}
//-----------------------------------------------------------------------------------------
void manualInput()
{
    int size, low = 0, high = 0, num;
    BinaryTree tree;
    std::cout << "enter number of values: ";
    std::cin >> size;
    std::cout << "enter your values: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> num;
        tree.insert(num);
    }
    while (low == high || low > high || low < 0)
    {
        std::cout << "\nenter a range of values (2 numbers): ";
        std::cin >> low;
        std::cin >> high;
        if (low < high)
        {
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Otvet: " << tree.Finallaba(low, high) << "\nyour tree: ";
    std::cout << std::endl;
    tree.print();
}
//-----------------------------------------------------------------------------------------
int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}