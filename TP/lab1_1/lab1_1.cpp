#include<iostream>
#include "Queue.h"
int main(){
    int InputCount;
    Queue<int> q1;
    std::cout << "input couunt of elements>>";
    std::cin >> InputCount;
    std::cout << "input elements>>";
    for (int i = 0; i < InputCount; i++) {
        int value;
        std::cin >> value;
        q1.Push(value);
    }
    q1.Print();
    Queue<int> q2;
    std::cout << "input couunt of elements for second queue>>";
    std::cin >> InputCount;
    std::cout << "input elements>>";

}