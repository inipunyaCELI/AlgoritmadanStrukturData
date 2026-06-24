#include "single_linked_list.h"
#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    SingleLinkedList sll;
    sll.init();

    for (int i = 0; i < N; ++i) {
        int val; std::cin >> val;
        sll.add_back(val);
    }

    const int K_INIT = K;
    Node* cur = sll.tail;

    while (sll.size > 1) {
        int steps = (K - 1) % sll.size;
        for (int step = 0; step < steps; ++step)
            cur = cur->next;

        Node* target = cur->next;
        int val = target->data;

        cur->next = target->next;
        if (target == sll.head) sll.head = cur->next;
        if (target == sll.tail) sll.tail = cur;

        delete target;
        sll.size--;

        if (val % 2 == 0) K++;
        else              K--;
        if (K <= 0) K = K_INIT;
    }

    std::cout << sll.head->data << "\n";
    sll.head->next = nullptr;
    sll.tail = sll.head;
    delete sll.head;
    sll.head = sll.tail = nullptr;
    sll.size = 0;
    return 0;
}