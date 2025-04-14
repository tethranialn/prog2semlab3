#include "List.h"
#include <iostream>

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

int List::getSize() const { return size; }

void List::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void List::removeLast(const char* value) {
    if (!head || !value) return;

    Node* lastMatch = nullptr;
    Node* prevToLast = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        bool match = true;
        int i = 0;
        while (value[i] != '\0' && current->data[i] != '\0') {
            if (value[i] != current->data[i]) {
                match = false;
                break;
            }
            i++;
        }
        if (match && value[i] == '\0' && current->data[i] == '\0') {
            lastMatch = current;
            prevToLast = prev;
        }
        prev = current;
        current = current->next;
    }
    //if
    if (lastMatch) {
        if (lastMatch == head) {
            head = head->next;
            if (!head) tail = nullptr;
        }
        else {
            prevToLast->next = lastMatch->next;
            if (lastMatch == tail) tail = prevToLast;
        }
        delete lastMatch;
        size--;
    }
}



List::Node::Node(const char* data, Node* next) {
    int len = 0;
    while (data[len] != '\0') len++;

    this->data = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        this->data[i] = data[i];
    }
    this->next = next;
}

List::Node::~Node() {
    delete[] data;
}
