#include "Queue.h"
#include <iostream>

// Конструктор копирования
template <typename T>
Queue<T>::Queue(const Queue<T>& obj) {
    count = obj.count;
    arr = new T[count];
    for (int i = 0; i < count; i++) {
        arr[i] = obj.arr[i];
        }
    }

// Деструктор
template <typename T>
Queue<T>::~Queue() {
    delete[] arr;
    }

// Добавление элемента в очередь
template <typename T>
void Queue<T>::Push(T item) {
    T* newArr = new T[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = arr[i];
        }
    newArr[count] = item;
    count++;
    delete[] arr;
    arr = newArr;
    }

// Извлечение элемента из очереди
template <typename T>
T Queue<T>::Pop() {
    if (count == 0) {
        //throw std::runtime_error("Queue is empty");
        std::cout<<"Empty";
        }
    T item = arr[0];
    T* newArr = new T[count - 1];
    for (int i = 1; i < count; i++) {
        newArr[i - 1] = arr[i];
        }
    count--;
    delete[] arr;
    arr = newArr;
    return item;
    }

// Получение элемента из очереди
template <typename T>
T Queue<T>::GetElement() const {
    if (count == 0) {
        //throw std::runtime_error("Queue is empty");
        std::cout << "Empty";
        }
    return arr[0];
    }

// Печать элементов очереди
template <typename T>
void Queue<T>::Print() {
    for (int i = 0; i < count; i++) {
        std::cout << arr[i] << " ";
        }
    std::cout << std::endl;
    }

// Явно инстанциируем класс для int (или других типов, которые планируете использовать)
template class Queue<int>;
