#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>

Node* build_linked_list_from_array(const int arr[], int n) {
    if(n <= 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i = 1; i < n; i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

TEST_CASE("Basic Linked List Operations") {
    Node* head = build_linked_list(5);
    std::ostringstream oss;
    Node* current = head;
    while(current){
        oss << current->data << " ";
        current = current->next;
    }
    CHECK(oss.str() == "1 2 3 4 5 ");
    CHECK(get_linked_list_data_item_value(head, 1) == 1);
    CHECK(get_linked_list_data_item_value(head, 3) == 3);
    CHECK(get_linked_list_data_item_value(head, 5) == 5);
    CHECK(get_linked_list_data_item_value(head, 6) == -1);

    delete_list_element(head, 1);
    CHECK(get_linked_list_data_item_value(head, 1) == 2);
    delete_list_element(head, 2); 
    CHECK(get_linked_list_data_item_value(head, 2) == 4);
    delete_entire_linked_list(head);
    CHECK(head == nullptr);
}

TEST_CASE("Copy and Pointer Jumping") {
    Node* head = build_linked_list(5);
    Node* copyHead = copy_linked_list(head);
    delete_list_element(head, 3);
    CHECK(get_linked_list_data_item_value(copyHead, 3) == 3);

    pointer_jumping(copyHead);
    CHECK(copyHead->next != nullptr);
    CHECK(copyHead->next->data == 5);
    CHECK(copyHead->next->next == nullptr);

    delete_entire_linked_list(head);
    delete_entire_linked_list(copyHead);
}

TEST_CASE("Prefix Sum Check") {
    int arr1[] = {1, 2, 3, 4};
    Node* head1 = build_linked_list_from_array(arr1, 4);
    CHECK(check_prefix_sum(head1) == 1);
    delete_entire_linked_list(head1);

    int arr2[] = {-1, -2, -3, -4};
    Node* head2 = build_linked_list_from_array(arr2, 4);
    CHECK(check_prefix_sum(head2) == -1);
    delete_entire_linked_list(head2);

    int arr3[] = {1, -3, 2};
    Node* head3 = build_linked_list_from_array(arr3, 3);
    CHECK(check_prefix_sum(head3) == 0);
    delete_entire_linked_list(head3);
}

int main(int argc, char** argv) {
    return doctest::Context().run();
}