#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

Node* build_linked_list(int n);
void print_linked_list(Node* head);
void delete_entire_linked_list(Node*& head);
int get_linked_list_data_item_value(Node* head, int node_number);
void delete_list_element(Node*& head, int node_number);

#endif