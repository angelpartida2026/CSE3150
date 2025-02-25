#include "LinkedList.h"
#include <iostream>

Node* build_linked_list(int n) {
    if(n <= 0) return nullptr;
    Node* head = new Node(1);
    Node* current = head;
    for(int i = 2; i <= n; i++){
        current->next = new Node(i);
        current = current->next;
    }
    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;
    while(current){
        std::cout << current->data << " ";
        current = current->next;
    }
}

void delete_entire_linked_list(Node*& head) {
    delete head;
    head = nullptr;
}

int get_linked_list_data_item_value(Node* head, int node_number) {
    Node* current = head;
    int count = 1;
    while(current){
        if(count == node_number)
            return current->data;
        current = current->next;
        count++;
    }
    return -1;
}

void delete_list_element(Node*& head, int node_number) {
    if(!head) return;
    if(node_number == 1){
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
    Node* current = head;
    for(int i = 1; i < node_number - 1 && current; i++){
        current = current->next;
    }
    if(!current || !current->next) return;
    Node* temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

Node* copy_linked_list(Node* head) {
    if (!head)
        return nullptr;
    return new Node(*head);
}

int check_prefix_sum(Node* head) {
    if (!head)
        return 0;
    int sum = 0;
    bool allPositive = true;
    bool allNegative = true;
    Node* current = head;
    while(current){
        sum += current->data;
        if(sum <= 0)
            allPositive = false;
        if(sum >= 0)
            allNegative = false;
        current = current->next;
    }
    if(allPositive)
        return 1;
    else if(allNegative)
        return -1;
    else
        return 0;
}

void pointer_jumping(Node* head) {
    if (!head)
        return;
    Node* last = head;
    while(last->next) {
        last = last->next;
    }
    Node* current = head;
    while(current && current != last) {
        Node* temp = current->next;
        current->next = last;
        current = temp;
    }
}