#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>

TEST_CASE("Testing build_linked_list and print_linked_list") {
    Node* head = build_linked_list(5);
    std::ostringstream oss;
    Node* current = head;
    while(current){
        oss << current->data << " ";
        current = current->next;
    }
    CHECK(oss.str() == "1 2 3 4 5 ");
    delete_entire_linked_list(head);
    CHECK(head == nullptr);
}

TEST_CASE("Testing get_linked_list_data_item_value") {
    Node* head = build_linked_list(5);
    CHECK(get_linked_list_data_item_value(head, 1) == 1);
    CHECK(get_linked_list_data_item_value(head, 3) == 3);
    CHECK(get_linked_list_data_item_value(head, 5) == 5);
    CHECK(get_linked_list_data_item_value(head, 6) == -1);
    delete_entire_linked_list(head);
}

TEST_CASE("Testing delete_list_element") {
    Node* head = build_linked_list(5);
    SUBCASE("Delete middle") {
        delete_list_element(head, 3);
        CHECK(get_linked_list_data_item_value(head, 3) == 4);
        CHECK(get_linked_list_data_item_value(head, 4) == 5);
    }
    SUBCASE("Delete head") {
        delete_list_element(head, 1);
        CHECK(get_linked_list_data_item_value(head, 1) == 2);
    }
    delete_entire_linked_list(head);
}

TEST_CASE("Testing delete_entire_linked_list") {
    Node* head = build_linked_list(3);
    delete_entire_linked_list(head);
    CHECK(head == nullptr);
}

int main(int argc, char** argv) {
    return doctest::Context().run();
}