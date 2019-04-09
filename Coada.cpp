#include "Coada.h"
#include <iostream>
#include <cstring>
#define INF 10000

using namespace std;

Coada::Coada(char *str) {
    for (int i = 0; i < strlen(str); ++i)
        push(str[i]);
}

Coada::Coada(const Coada &obj) {
    first = last = nullptr;
    top = 0;
    Node * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }
}

void Coada::push(char x) {
    insertAfter(x);
}

void Coada::pop() {
    popFront();
}

char Coada::topp() {
    return begin()->getX();
}

Coada Coada::operator+(const Coada &obj) {
    Coada _tmp;
    Node * cross = this->first;
    while(cross != nullptr) {
        _tmp.insertAfter(cross->getX());
        cross = cross->getNext();
    }

    cross = obj.first;
    while(cross != nullptr) {
        _tmp.insertAfter(cross->getX());
        cross = cross->getNext();
    }

    return _tmp;
}

Coada Coada::operator-(const Coada &obj) {
    Node * cross1 = this->first;
    Node * cross2 = obj.first;
    bool flag = true;

    while(cross1 != nullptr && cross2 != nullptr) {
        if(*cross1 != *cross2) {
            flag = false;
            break;
        }
        cross1 = cross1->getNext();
        cross2 = cross2->getNext();
    }

    Coada __tmp;
    if (!flag || cross1 != nullptr) {
        while(cross1 != nullptr) {
            __tmp.insertAfter(cross1->getX());
            cross1 = cross1->getNext();
        }
    }

    return __tmp;
}

istream &operator>>(istream &in, Coada &obj) {
    long long n;
    do {
        cout << "Number of elements : ";
        in >> n;
        if(n < 0 || n > INF)
            cout << "The number of the elements need to be in range [0, " << INF << "]\n";
    }while(n < 0 || n > INF);

    if(n > 0) {
        char __tmp;
        cout << "Insert the elements of the Queue : ";
        for (int i = 0; i < n; ++i) {
            in >> __tmp;
            obj.insertAfter(__tmp);
        }
    }

    return in;
}


ostream &operator<<(ostream &out, const Coada &obj) {
    Node * cross = obj.first;
    while(cross != nullptr) {
        out << cross->getX() << ' ';
        cross = cross->getNext();
    }
    return out;
}
