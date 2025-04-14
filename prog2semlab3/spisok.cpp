#include "spisok.h"
#include <iostream>

SPISOK::SPISOK() : head(nullptr), tail(nullptr), size(0) {}

SPISOK::~SPISOK() 
{
    clear();
}

int SPISOK::getSize() const 
{ 
    return size;
}

void SPISOK::clear() 
{
    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void SPISOK::removeAllExcept(const char* value) 
{
    if (!head || !value) return;
    Node* current = head;
    Node* prev = nullptr;
    while (current)
    {
        bool match = true;
        int i = 0;
        while (value[i] != '\0' && current->data[i] != '\0')
        {
            if (value[i] != current->data[i])
            {
                match = false;
                break;
            }
            i++;
        }
        if (match && value[i] == '\0' && current->data[i] == '\0')
        {
            prev = current;
            current = current->next;
        }
        else
        {
            Node* toDelete = current;
            current = current->next;
            if (toDelete == head)
            {
                head = current;
                if (!head) tail = nullptr;
            }
            else
            {
                prev->next = current;
                if (toDelete == tail) tail = prev;
            }
            delete toDelete;
            size--;
        }
    }
}

SPISOK::Node::Node(const char* data, Node* next) 
{
    int len = 0;
    while (data[len] != '\0') len++;

    this->data = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        this->data[i] = data[i];
    }
    this->next = next;
}

SPISOK::Node::~Node()
{
    delete[] data;
}

void SPISOK::push_back(const char* data) 
{
    if (!data) return;
    Node* newNode = new Node(data);
    if (!head) 
    {
        head = tail = newNode;
    }
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SPISOK::printToFile(ofstream& out, bool showInfo) const {
    if (!out) return;
    if (showInfo) 
    {
        out << "contents of the list:\n\n";
    }
    Node* current = head;
    while (current) 
    {
        out << "->" << current->data << '\n';
        current = current->next;
    }
    if (showInfo)
    {
        out << "\nnumber of elements in the list: " << size << '\n';
    }
}