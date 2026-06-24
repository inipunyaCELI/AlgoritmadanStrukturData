#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return head == nullptr;
}

void SingleLinkedList::add_front(int val) {
    Node* n = new Node{val, nullptr};
    if (is_empty()) {
        n->next = n;
        head = tail = n;
    } else {
        n->next = head;
        tail->next = n;
        head = n;
    }
    ++size;
}

void SingleLinkedList::add_back(int val) {
    Node* n = new Node{val, nullptr};
    if (is_empty()) {
        n->next = n;
        head = tail = n;
    } else {
        n->next = head;
        tail->next = n;
        tail = n;
    }
    ++size;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size)
        throw std::out_of_range("add_idx: index out of range");
    if (idx == 0)    { add_front(val); return; }
    if (idx == size) { add_back(val);  return; }
    Node* cur = head;
    for (int i = 0; i < idx - 1; ++i) cur = cur->next;
    Node* n = new Node{val, cur->next};
    cur->next = n;
    ++size;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::underflow_error("delete_front: list is empty");
    Node* old = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete old;
    --size;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::underflow_error("delete_back: list is empty");
    Node* old = tail;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        Node* cur = head;
        while (cur->next != tail) cur = cur->next;
        cur->next = head;
        tail = cur;
    }
    delete old;
    --size;
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty())          throw std::underflow_error("delete_idx: list is empty");
    if (idx < 0 || idx >= size) throw std::out_of_range("delete_idx: index out of range");
    if (idx == 0)        { delete_front(); return; }
    if (idx == size - 1) { delete_back();  return; }
    Node* cur = head;
    for (int i = 0; i < idx - 1; ++i) cur = cur->next;
    Node* target = cur->next;
    cur->next = target->next;
    delete target;
    --size;
}

void SingleLinkedList::display() {
    if (is_empty()) { std::cout << "(empty)\n"; return; }
    Node* cur = head;
    do {
        std::cout << cur->data;
        cur = cur->next;
        if (cur != head) std::cout << " -> ";
    } while (cur != head);
    std::cout << "\n";
}

int SingleLinkedList::get(int idx) {
    if (is_empty())             throw std::underflow_error("get: list is empty");
    if (idx < 0 || idx >= size) throw std::out_of_range("get: index out of range");
    Node* cur = head;
    for (int i = 0; i < idx; ++i) cur = cur->next;
    return cur->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty())             throw std::underflow_error("set: list is empty");
    if (idx < 0 || idx >= size) throw std::out_of_range("set: index out of range");
    Node* cur = head;
    for (int i = 0; i < idx; ++i) cur = cur->next;
    cur->data = val;
}

void SingleLinkedList::clear() {
    if (is_empty()) return;
    Node* cur = head->next;
    while (cur != head) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    delete head;
    head = tail = nullptr;
    size = 0;
}