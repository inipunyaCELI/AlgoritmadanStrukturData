#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>

void DoubleLinkedList::init()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
bool DoubleLinkedList::is_empty() { return head == nullptr; }

void DoubleLinkedList::add_front(char val)
{
    Node *n = new Node{val, nullptr, nullptr};
    if (is_empty())
    {
        n->next = n;
        n->prev = n;
        head = tail = n;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        head->prev = n;
        tail->next = n;
        head = n;
    }
    ++size;
}

void DoubleLinkedList::add_back(char val)
{
    Node *n = new Node{val, nullptr, nullptr};
    if (is_empty())
    {
        n->next = n;
        n->prev = n;
        head = tail = n;
    }
    else
    {
        n->prev = tail;
        n->next = head;
        tail->next = n;
        head->prev = n;
        tail = n;
    }
    ++size;
}

void DoubleLinkedList::add_idx(char val, int idx)
{
    if (idx < 0 || idx > size)
        return;
    if (idx == 0)
    {
        add_front(val);
        return;
    }
    if (idx == size)
    {
        add_back(val);
        return;
    }
    Node *cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    Node *n = new Node{val, cur, cur->prev};
    cur->prev->next = n;
    cur->prev = n;
    ++size;
}

void DoubleLinkedList::delete_front()
{
    if (is_empty())
        return;
    Node *old = head;
    if (size == 1)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete old;
    --size;
}

void DoubleLinkedList::delete_back()
{
    if (is_empty())
        return;
    Node *old = tail;
    if (size == 1)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete old;
    --size;
}

void DoubleLinkedList::delete_idx(int idx)
{
    if (is_empty())
        return;
    if (idx < 0 || idx >= size)
        return;
    if (idx == 0)
    {
        delete_front();
        return;
    }
    if (idx == size - 1)
    {
        delete_back();
        return;
    }
    Node *cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    --size;
}

void DoubleLinkedList::display()
{
    if (is_empty())
    {
        std::cout << "(empty)\n";
        return;
    }
    Node *cur = head;
    for (int i = 0; i < size; ++i)
    {
        std::cout << cur->data;
        if (i < size - 1)
            std::cout << "<->";
        cur = cur->next;
    }
    std::cout << "\n";
}

char DoubleLinkedList::get(int idx)
{
    if (is_empty())
        throw std::underflow_error("get: list is empty");
    if (idx < 0 || idx >= size)
        throw std::out_of_range("get: index out of range");
    Node *cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    return cur->data;
}

void DoubleLinkedList::set(char val, int idx)
{
    if (is_empty())
        throw std::underflow_error("set: list is empty");
    if (idx < 0 || idx >= size)
        throw std::out_of_range("set: index out of range");
    Node *cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    cur->data = val;
}

void DoubleLinkedList::clear()
{
    while (!is_empty())
        delete_front();
}