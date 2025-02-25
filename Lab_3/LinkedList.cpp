#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(int n) {
    if(n <= 0) { head = nullptr; return; }
    head = new Node(1);
    Node* cur = head;
    for(int i = 2; i <= n; i++){
        cur->next = new Node(i);
        cur = cur->next;
    }
    cur->next = cur;
}

LinkedList::LinkedList(const LinkedList &other) {
    if(!other.head) { head = nullptr; return; }
    head = new Node(other.head->data);
    Node* curNew = head;
    Node* curOther = other.head;
    while(curOther->next != curOther) {
        curOther = curOther->next;
        curNew->next = new Node(curOther->data);
        curNew = curNew->next;
    }
    curNew->next = curNew;
}

LinkedList::~LinkedList() {
    if(!head) return;
    Node* last = head;
    while(last->next != last) last = last->next;
    last->next = nullptr; 
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::print() const {
    if(!head) return;
    Node* cur = head;
    do {
        std::cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);
    std::cout << std::endl;
}

void LinkedList::deleteNode(int index) {
    if(!head) return;
    if(index == 1) {
        if(head->next == head) { delete head; head = nullptr; return; }
        Node* last = head;
        while(last->next != head) last = last->next;
        Node* temp = head;
        head = head->next;
        last->next = head;
        temp->next = nullptr;
        delete temp;
        return;
    }
    Node* cur = head;
    for(int i = 1; i < index - 1 && cur->next != head; i++) cur = cur->next;
    if(cur->next == head) return;
    Node* temp = cur->next;
    cur->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

int LinkedList::getValue(int index) const {
    if(!head) return -1;
    Node* cur = head;
    int count = 1;
    do {
        if(count == index)
            return cur->data;
        cur = cur->next;
        count++;
    } while(cur != head);
    return -1;
}

int LinkedList::prefixSumType() const {
    if(!head) return 0;
    int sum = 0;
    bool nonneg = true, nonpos = true;
    Node* cur = head;
    do {
        sum += cur->data;
        if(sum < 0) nonneg = false;
        if(sum > 0) nonpos = false;
        cur = cur->next;
    } while(cur != head);
    return nonneg ? 1 : nonpos ? -1 : 0;
}

void LinkedList::pointerJumping() {
    if(!head) return;
    Node* last = head;
    while(last->next != head) last = last->next;
    Node* cur = head;
    while(cur && cur != last) {
        cur->next = last;
        cur = cur->next;
        if(cur == last) break;
    }
}