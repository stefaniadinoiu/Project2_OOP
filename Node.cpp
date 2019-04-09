#include "Node.h"

Node::Node(char x) {
    this->x = x;
    this->next = nullptr;
}

char Node::getX() {
    return x;
}

void Node::setX(char x) {
    this->x = x;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node * next) {
    this->next = next;
}

bool Node::operator<(const Node &B) const{
    return this->x < B.x;
}

bool Node::operator>(const Node &B) const{
    return this->x > B.x;
}

bool Node::operator<=(const Node &B) const{
    return this->x <= B.x;
}

bool Node::operator>=(const Node &B) const{
    return this->x >= B.x;
}

bool Node::operator!=(const Node &B) const{
    return this->x != B.x;
}

bool Node::operator==(const Node &B) const{
    return this->x == B.x;
}

void swap(Node &A, Node &B) {
    char __tmp = A.x;
    A.x = B.x;
    B.x = __tmp;
}
