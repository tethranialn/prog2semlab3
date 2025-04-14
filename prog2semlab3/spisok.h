#pragma once
#include <fstream>
using namespace std;
class SPISOK 
{
public:
    SPISOK();
    ~SPISOK();
    void push_back(const char* data);
    void clear();
    int getSize() const;
    void removeAllExcept(const char* value);
    void printToFile(ofstream& out, bool showInfo) const;
private:
    struct Node 
    {
        char* data;
        Node* next;
        Node(const char* data, Node* next = nullptr);
        ~Node();
    };
    Node* head;
    Node* tail;
    int size;
};
