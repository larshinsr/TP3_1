#pragma once
template <typename T>
class Queue
{
    private:
        T* arr; // динамический массив
        int count; // количество элементов в очереди

    public:
        Queue(){ count=0; } //конструктор по умолчанию
        Queue(const Queue& obj); //конструктор копирования
        ~Queue();
        void Push(T item);
        T Pop();
        bool IsEmpty() const {return count == 0;}
        T GetElement() const;
        int GetCount() const {return count;}
        void Print();
};