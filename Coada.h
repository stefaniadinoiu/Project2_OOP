#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED

#include "LinkedList.h"

class Coada : protected LinkedList {
    public:
        Coada() = default;
        Coada(char *str);
        Coada(const Coada &);

        void push(char);
        virtual void pop();
        virtual char topp();

        Coada operator+(const Coada &);
        Coada operator-(const Coada &);

        friend istream &operator>>(istream &, Coada &);
        friend ostream &operator<<(ostream &, const Coada &);
};

#endif // COADA_H_INCLUDED
