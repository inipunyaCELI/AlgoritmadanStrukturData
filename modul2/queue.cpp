#include "queue.h"
#include <stdexcept>

Queue::Queue()
{
    front = 0;
    rear = -1;
    size = 0;
}

void Queue::enqueue(int x)
{
    if (size == 100)
    {
        throw std::overflow_error("Queue penuh");
    }
    rear = (rear + 1) % 100;
    arr[rear] = x;
    size++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::underflow_error("Queue kosong");
    }
    int val = arr[front];
    front = (front + 1) % 100;
    size--;
    return val;
}

bool Queue::isEmpty()
{
    return size == 0;
}
