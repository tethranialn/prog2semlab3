#pragma once

#include <fstream>

using namespace std;
class List {
public:
    List();
    ~List();

    void push_back(const char* data);
    void clear();
    int getSize() const;
    void removeLast(const char* value);
    void printToFile(ofstream& out, bool showInfo) const;

private:
    struct Node {
        char* data;
        Node* next;
        Node(const char* data, Node* next = nullptr);
        ~Node();
    };

    Node* head;
    Node* tail;
    int size;
};

/*
struct Elem
{
    int N; Elem* next;
};
void Init(Elem* p, Elem* a = NULL)
{
    p->N = 0; p->next = a;
}
void InitT(Elem* p, int t, Elem* a)
{
    p->N = t; p->next = a;
}
void SetN(Elem* p, int t) { p->N = t; }
void SetNext(Elem* p, Elem* a) { p->next = a; }
int GetN(Elem* p) { return p->N; }
Elem* GetNext(Elem* p) { return p->next; }
void NewElem(Elem** p)
{
    *p = new Elem; Init(*p);
}

--------------------------------------------------
class Elem
{
    int N; Elem* next;
public: void Init(Elem* a);
      void InitT(int t, Elem* a);
      void SetN(int t);
      SetNext(Elem* a);
      void int GetN(void)
          Elem* GetNext(void);
};
void Elem::Init(Elem* a = NULL)
{
    N = 0; next = a;
}
void Elem::InitT(int t, Elem* a)
{
    N = t; next = a;
}
void Elem::SetN(int t) { N = t; }
void Elem::SetNext(Elem* a) { next = a; }
int Elem::GetN(void) { return N; }
Elem* Elem::GetNext(void) { return next; }
void NewElem(Elem** p)
{
    *p = new Elem; (*p)->Init();
}
*/