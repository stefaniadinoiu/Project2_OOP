#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include "Coada.h"

class Deque : public Coada {
    public:
        Deque()= default;
        Deque(char *str);
        Deque(const Deque &);

        void push_back(char x);
        void push_front(char x);
        void pop_back();
        void pop_front();

        Deque operator+(const Deque &);
        Deque operator-(const Deque &);

        friend istream &operator>>(istream &, Deque &);
        friend ostream &operator<<(ostream &, const Deque &);
};


#endif // DEQUE_H_INCLUDED
