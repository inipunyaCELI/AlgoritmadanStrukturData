#include "double_linked_list.h"
#include <iostream>
using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        list.add_back(c);
    }

    Node *alpha = list.head;
    Node *beta = list.tail;

    for (int ronde = 0; ronde < R; ronde++)
    {
        long long X, Y;
        cin >> X >> Y;

        if (list.size == 0)
            break;

        long long la = X % (long long)list.size;
        long long lb = Y % (long long)list.size;

        for (long long j = 0; j < la; j++)
            alpha = alpha->next;
        for (long long j = 0; j < lb; j++)
            beta = beta->prev;

        if (alpha == beta)
        {
            if (list.size == 1)
            {
                delete alpha;
                list.head = list.tail = nullptr;
                list.size = 0;
                break;
            }

            Node *next_node = alpha->next;
            Node *prev_node = alpha->prev;

            prev_node->next = next_node;
            next_node->prev = prev_node;
            if (alpha == list.head)
                list.head = next_node;
            if (alpha == list.tail)
                list.tail = prev_node;
            delete alpha;
            list.size--;

            alpha = next_node;
            beta = prev_node;

            if (list.size == 0)
                break;
        }
        else if ((alpha->next == beta && beta != list.head) ||
                 (beta->next == alpha && alpha != list.head))
        {
            char tmp = alpha->data;
            alpha->data = beta->data;
            beta->data = tmp;
        }
    }

    if (list.size == 0)
    {
        cout << "EMPTY" << endl;
    }
    else
    {
        Node *curr = list.head;
        for (int i = 0; i < list.size; i++)
        {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }

    list.clear();
    return 0;
}