#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
    Node(const Node &other) : data(other.data), next(nullptr) {
        if(other.next)
            next = new Node(*other.next);
    }
    ~Node() { delete next; }
};

#endif