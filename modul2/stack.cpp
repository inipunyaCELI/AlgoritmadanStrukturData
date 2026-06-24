#include "stack.h"
#include <stdexcept>

stack::stack()
{
    top = -1;
}

void stack::push(int x)
{
    if (top == 99)
    {
        throw std::overflow_error("Stack Penuh");
    }
    arr[++top] = x;
}

int stack::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack Kosong");
    }
    return arr[top--];
}

int stack::peek()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack Kosong");
    }
    return arr[top];
}

bool stack::isEmpty()
{
    return top == -1;
}
