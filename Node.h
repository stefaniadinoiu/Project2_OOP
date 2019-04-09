#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
private:
    char x;
    Node * next;
public:
    Node(char);

    char getX();
    void setX(char);
    Node *getNext();
    void setNext(Node *);

    //Operator overloading
    bool operator<(const Node &) const;
    bool operator>(const Node &) const;
    bool operator<=(const Node &) const;
    bool operator>=(const Node &) const;
    bool operator!=(const Node &) const;
    bool operator==(const Node &) const;

    friend void swap(Node &A, Node &B);
};

#endif // NODE_H_INCLUDED
