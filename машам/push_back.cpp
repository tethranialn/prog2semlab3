#include "List.h"
void List::push_back(const char* data) {
    if (!data) return;

    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}