#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LinkedList.h"
#include <sstream>
#include <iostream>

TEST_CASE("Test build and print") {
    LinkedList list(5);
    std::ostringstream oss;
    Node* cur = list.head;
    do {
        oss << cur->data << " ";
        cur = cur->next;
    } while(cur != list.head);
    CHECK(oss.str() == "1 2 3 4 5 ");
}

TEST_CASE("Test getValue") {
    LinkedList list(5);
    CHECK(list.getValue(1) == 1);
    CHECK(list.getValue(3) == 3);
    CHECK(list.getValue(5) == 5);
    CHECK(list.getValue(6) == -1);
}

TEST_CASE("Test deleteNode") {
    LinkedList list(5);
    SUBCASE("Delete middle") {
        list.deleteNode(3);
        CHECK(list.getValue(3) == 4);
        CHECK(list.getValue(4) == 5);
    }
    SUBCASE("Delete head") {
        list.deleteNode(1);
        CHECK(list.getValue(1) == 2);
    }
}

TEST_CASE("Test prefixSumType") {
    LinkedList list(5);.
    CHECK(list.prefixSumType() == 1);
}

TEST_CASE("Test pointerJumping") {
    LinkedList list(5);
    list.pointerJumping();
    Node* last = list.head;
    while(last->next != last) last = last->next;
    if(list.head != last)
        CHECK(list.head->next == last);
}

TEST_CASE("Test copy constructor") {
    LinkedList list1(5);
    LinkedList list2 = list1;
    CHECK(list2.getValue(1) == list1.getValue(1));
    CHECK(list2.getValue(3) == list1.getValue(3));
    CHECK(list2.getValue(5) == list1.getValue(5));
}

int main(int argc, char** argv) {
    return doctest::Context().run();
}