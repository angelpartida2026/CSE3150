#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    Node* head;
    LinkedList(int n);
    LinkedList(const LinkedList &other);
    ~LinkedList();
    void print() const;
    void deleteNode(int index);
    int getValue(int index) const;
    int prefixSumType() const; 
    void pointerJumping();
};

#endif