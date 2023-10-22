#include "Queue.h"
#include<iostream>

Queue::Queue() : arr(nullptr), count(0) {}

Queue::Queue(const Queue& obj) 
{
    count = obj.count;
    arr = new int[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = obj.arr[i];
    }
}

Queue::~Queue() 
{
    delete[] arr;
}

void Queue::Push(int item) 
{
    int* newArr = new int[count + 1];
    for (int i = 0; i < count; i++) 
    {
        newArr[i] = arr[i];
    }
    newArr[count] = item;
    count++;
    delete[] arr;
    arr = newArr;
}

int Queue::Pop() 
{
    if (IsEmpty()) 
    {
        throw std::runtime_error("Queue is empty");
    }
    int item = arr[0];
    int* newArr = new int[count - 1];
    for (int i = 1; i < count; i++) 
    {
        newArr[i - 1] = arr[i];
    }
    count--;
    delete[] arr;
    arr = newArr;
    return item;
}

bool Queue::IsEmpty() const 
{
    return count == 0;
}

int Queue::GetElement() const 
{
    if (IsEmpty()) 
{
        throw std::runtime_error("Queue is empty");
        }
    return arr[0];
    }

int Queue::GetCount() const 
{
    return count;
}

void Queue::Print() const 
{
    for (int i = 0; i < count; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

Queue Queue::Merge(const Queue& q1, const Queue& q2) 
{
    Queue mergedQueue;
    if (q1.GetCount() != q2.GetCount())
    {
        std::cout<<"different length"<<std::endl;
    }
    else
    {
        
        Queue tempQ1 = q1;
        Queue tempQ2 = q2;
        while (!tempQ1.IsEmpty() || !tempQ2.IsEmpty()) 
        {
            if (!tempQ1.IsEmpty()) 
            {
                mergedQueue.Push(tempQ1.Pop());
            }
            if (!tempQ2.IsEmpty()) 
            {
                mergedQueue.Push(tempQ2.Pop());
            }
        }
        
    }
    return mergedQueue;
}
