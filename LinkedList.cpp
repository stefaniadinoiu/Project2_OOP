#include "LinkedList.h"
#include <iostream>
#define INF 10000

using namespace std;

LinkedList::LinkedList() {
    first = last = nullptr;
    top = 0;
}

LinkedList::LinkedList(const LinkedList &obj) {
    first = last = nullptr;
    top = 0;
    Node * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }
}

LinkedList::~LinkedList() {
    while(first) {
        popFront();
    }

    first = last = nullptr;
}

void LinkedList::insertFront(char x) {
    ++top;
    auto * elem = new Node(x);
    elem->setNext(first);
    if(first == nullptr) {
        first = last = elem;
    }
    else {
        first = elem;
    }
}

void LinkedList::insertAfter(char x) {
    ++top;
    auto * elem = new Node(x);
    elem->setNext(nullptr);
    if(last == nullptr) {
        first = last = elem;
    }
    else {
        last->setNext(elem);
        last = elem;
    }
}

void LinkedList::popFront() {
    if(first != nullptr) {
        --top;
        Node * __tmp = first;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            first = first->getNext();
        }
        delete __tmp;
    }
}

void LinkedList::popLast() {
    if(last != nullptr) {
        --top;
        Node * __tmp = last;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            Node * cross = first;
            while(cross->getNext() != last) {
                cross = cross->getNext();
            }
            cross->setNext(nullptr);
            last = cross;
        }
        delete __tmp;
    }
}

void LinkedList::popValue(char x) {
    if(first != nullptr) {
        while(first != nullptr && first->getX() == x) {
            popFront();
            --top;
        }
        while(last != nullptr && last->getX() == x) {
            popLast();
            --top;
        }

        Node *__tmp = nullptr;
        Node * cross = first;
        while(cross && cross->getNext()){
            if(cross->getNext()->getX() == x) {
                --top;
                __tmp = cross->getNext();
                cross->setNext(cross->getNext()->getNext());
                delete __tmp;
            }
            else cross = cross->getNext();
        }
    }
}


void LinkedList::popNode(Node *p) {
    if(first != nullptr) {
        if(first == p) {
            --top;
            popFront();
        }
        else if(last == p) {
            --top;
            popLast();
        }
        else if(first == last) {
            ;
        }
        else {
            Node * cross = first;
            Node * preCross = nullptr;
            while(cross != nullptr) {
                if(cross == p)
                    break;
                preCross = cross;
                cross = cross->getNext();
            }
            if(preCross != nullptr && cross != nullptr && cross == p) {
                --top;
                preCross->setNext(cross->getNext());
                delete cross;
            }

        }
    }
}


int LinkedList::size() {
    return this->top;
}


Node &LinkedList::operator[](const int index) {
    assert(index >= 0 && index < top); //testeaza daca index-ul se afla in range-ul listei

    if(index == 0)
        return *first;
    else if(index == top - 1)
        return *last;

    Node * cross = first;
    int count = 0;

    while(count < index && cross != last) {
        ++count;
        cross = cross->getNext();
    }

    return *cross;
}

bool LinkedList::empty() const {
    return first == nullptr;
}

void LinkedList::clear() {
    while(!empty())
        this->popFront();
}


Node *LinkedList::begin() {
    return first;
}

Node *LinkedList::end() {
    return last;
}

LinkedList &LinkedList::operator=(const LinkedList &obj) {
    if(this == &obj)
        return *this;

    //delete everything from the current list
    this->clear();

    //make deep copy of the list from instance obj
    Node * cross = obj.first;
    while(cross){
        this->insertAfter(cross->getX());
        cross = cross->getNext();
    }

    return *this;
}

bool LinkedList::operator<(const LinkedList &obj) const{
    if(obj.top == this->top) {
        Node * cross1 = this->first;
        Node * cross2 = obj.first;

        while(cross1 != nullptr && cross2 != nullptr) {
            if(*cross1 < *cross2) {
                return true;
            }
            else if(*cross1 > *cross2) {
                return false;
            }
            cross1 = cross1->getNext();
            cross2 = cross2->getNext();
        }

        return false;
    }
    else return this->top < obj.top;
}

bool LinkedList::operator==(const LinkedList &obj) const{
    if(this->top == obj.top) {
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

        return flag;
    }

    return false;
}

bool LinkedList::operator!=(const LinkedList &obj) const{
    return *this == obj ? false : true;
}

LinkedList LinkedList::operator+(const LinkedList &obj) {
    LinkedList _tmp;
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

LinkedList LinkedList::operator-(const LinkedList &obj) {
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

    LinkedList __tmp;
    if (!flag || cross1 != nullptr) {
        while(cross1 != nullptr) {
            __tmp.insertAfter(cross1->getX());
            cross1 = cross1->getNext();
        }
    }

    return __tmp;
}

istream &operator>>(istream &in, LinkedList &obj) {
    long long n;
    do {
        cout << "Number of elements : ";
        in >> n;
        if(n < 0 || n > INF)
            cout << "The number of the elements need to be in range [0, " << INF << "]\n";
    }while(n < 0 || n > INF);

    if(n > 0) {
        char __tmp;
        cout << "Insert the elements of the Linked List : ";
        for (int i = 0; i < n; ++i) {
            in >> __tmp;
            obj.insertAfter(__tmp);
        }
    }

    return in;
}


ostream &operator<<(ostream &out, const LinkedList &obj) {
    Node * cross = obj.first;
    while(cross != nullptr) {
        out << cross->getX() << ' ';
        cross = cross->getNext();
    }
    return out;
}
