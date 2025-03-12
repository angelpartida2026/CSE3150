#include "LinkedList.h"

LinkedList::LinkedList() 
    : root(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
    : root(nullptr)
{
    Node* current = other.root;
    while (current) {
        push(current->data);
        current = current->next;
    }
}

LinkedList::LinkedList(LinkedList&& other) noexcept
    : root(other.root),
      nodeAddresses(std::move(other.nodeAddresses))
{
    other.root = nullptr;
    other.nodeAddresses.clear();
}

LinkedList::~LinkedList() {
    Node* current = root;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    root = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        Node* current = root;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        root = nullptr;
        nodeAddresses.clear();
        Node* otherCurr = other.root;
        while (otherCurr) {
            push(otherCurr->data);
            otherCurr = otherCurr->next;
        }
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        Node* current = root;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        root = nullptr;
        nodeAddresses.clear();
        root = other.root;
        nodeAddresses = std::move(other.nodeAddresses);
        other.root = nullptr;
        other.nodeAddresses.clear();
    }
    return *this;
}

void LinkedList::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = root;
    root = newNode;
    nodeAddresses.push_back(static_cast<void*>(newNode));
}

std::ostream& operator<<(std::ostream &os, const LinkedList &linkedList) {
    LinkedList::Node* current = linkedList.root;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}