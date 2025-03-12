#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* root;
    std::vector<void*> nodeAddresses;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    ~LinkedList();
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;
    void push(int val);
    friend std::ostream& operator<<(std::ostream &os, const LinkedList &linkedList);
};

#endif