#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "Coada.h"

class PriorityQueue: public Coada {
    char MaxElem;
public:
    PriorityQueue() = default;
    PriorityQueue(char *str);
    PriorityQueue(const PriorityQueue &obj);

    char topp();
    void pop();

    PriorityQueue operator+(const PriorityQueue &);
    PriorityQueue operator-(const PriorityQueue &);

    friend istream &operator>>(istream &, PriorityQueue &);
    friend ostream &operator<<(ostream &, const PriorityQueue &);
};


#endif // PRIORITYQUEUE_H_INCLUDED
