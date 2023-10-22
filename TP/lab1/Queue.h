#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<exception>
class Queue 
{
    private:
    int* arr; // динамический массив
    int count; // количество элементов в очереди

    public:
    Queue();                    // Конструктор по умолчанию
    Queue(const Queue& obj);    // Конструктор копирования
    ~Queue();                   // Деструктор
    void Push(int item);        // Добавить элемент в конец очереди
    int Pop();                  // Извлечь элемент из начала очереди
    bool IsEmpty() const;       // Проверить, пуста ли очередь
    int GetElement() const;     // Получить элемент из начала очереди
    int GetCount() const;       // Получить количество элементов в очереди
    void Print() const;         // Функция для печати элементов очереди
    static Queue Merge(const Queue& q1, const Queue& q2); // Слияние двух очередей
    };

#endif
