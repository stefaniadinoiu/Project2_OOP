#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <ostream>
#include <cassert>

using namespace std;

class LinkedList{
protected:
    Node * first, *last;
    int top; //variabila automatica se aloca pe stack sau heap(in acelasi segment de memorie)
    Node &operator[](int);
    int lomuto(int, int);
    void qsort(int, int);
public:
    //Constructor and destructor
    LinkedList();
    LinkedList(const LinkedList &);
    virtual ~LinkedList();

    //Methods to manipulate the LinkedList

    void insertFront(char);
    void insertAfter(char);
    void popFront();
    void popLast();
    void popValue(char);
    void popNode(Node *);
    void clear();
    int size();
    bool empty() const;
    Node *begin();
    Node *end();

    //Operator overloading
    LinkedList &operator=(const LinkedList &);
    bool operator<(const LinkedList &) const;
    bool operator==(const LinkedList &) const;
    bool operator!=(const LinkedList &) const;
    LinkedList operator+(const LinkedList &);
    LinkedList operator-(const LinkedList &);

    friend istream &operator>>(istream &, LinkedList &);
    friend ostream &operator<<(ostream &, const LinkedList &);
};

#endif // LINKEDLIST_H_INCLUDED
