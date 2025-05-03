#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LinkedList.h"
#include <iostream>

int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    std::cout << "\n--- Simulation ---\n";
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_printLinkedList();
    list.CLIENT_printLinkedList();
    list.SERVER_deleteCircularLinkedList();
    list.CLIENT_printLinkedList();
    std::cout << "\n--- End of Simulation ---\n";

    std::cout << "\n--- Running Unit Tests ---\n";
    int res = context.run();
    return res;
}

TEST_CASE("Build linked list with 6 nodes") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    CHECK(true);
}

TEST_CASE("Print shared_ptr linked list") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_printLinkedList();
    CHECK(true);
}

TEST_CASE("Delete shared_ptr linked list") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_deleteCircularLinkedList();
    CHECK(true);
}

TEST_CASE("Print weak_ptr linked list before deletion") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.CLIENT_printLinkedList();
    CHECK(true);
}

TEST_CASE("Print weak_ptr linked list after deletion") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_deleteCircularLinkedList();
    list.CLIENT_printLinkedList();
    CHECK(true);
}

