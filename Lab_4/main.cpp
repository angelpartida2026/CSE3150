#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"
#include <sstream>

TEST_CASE("LinkedList Move Constructor") {
    LinkedList list1;
    list1.push(10);
    list1.push(20);
    list1.push(30);

    LinkedList list2(std::move(list1));

    std::ostringstream oss1;
    oss1 << list1;
    CHECK(oss1.str().empty());

    std::ostringstream oss2;
    oss2 << list2;
    CHECK(oss2.str() == "30 20 10 ");
}

TEST_CASE("LinkedList Move Assignment") {
    LinkedList list1;
    list1.push(100);
    list1.push(200);

    LinkedList list2;
    list2.push(999);

    list2 = std::move(list1);

    std::ostringstream oss1;
    oss1 << list1;
    CHECK(oss1.str().empty());

    std::ostringstream oss2;
    oss2 << list2;
    CHECK(oss2.str() == "200 100 ");
}

TEST_CASE("Moving an empty list") {
    LinkedList emptyList;
    LinkedList list3(std::move(emptyList));
    std::ostringstream oss;
    oss << list3;
    CHECK(oss.str().empty());
}

TEST_CASE("Moving a single-element list") {
    LinkedList single;
    single.push(42);
    LinkedList moved(std::move(single));
    std::ostringstream oss;
    oss << single;
    CHECK(oss.str().empty());
    std::ostringstream oss2;
    oss2 << moved;
    CHECK(oss2.str() == "42 ");
}
