#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <unistd.h>
#include "TimedSharedPtr.h"

struct Node {
    Node(int v) : val(v) {}
    int val;
    TimedSharedPtr<Node> next;
};

int run_output() {
    std::cout << "--- Test ---" << std::endl;
    TimedSharedPtr<Node> myNode(new Node(7), 1); // this expires after 1 second
    TimedSharedPtr<Node> myOtherNode = myNode;

    sleep(1);
    std::cout << "myNode.get() address: <" << myNode.get() << ">" << std::endl;
    std::cout << "myNode.use_count(): " << myNode.use_count() << std::endl;
    std::cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << std::endl;

    sleep(1);
    std::cout << "The ptr should have expired: " << std::endl;
    std::cout << "myNode.get() address: <" << myNode.get() << ">" << std::endl;
    std::cout << "-----------" << std::endl;
    {
        TimedSharedPtr<int> p(new int(42));
        std::cout << p.get() << std::endl;
        std::cout << "p.use_count(): " << p.use_count() << std::endl;

        TimedSharedPtr<int> q = p;
        std::cout << "p.use_count(): " << p.use_count() << std::endl;
        std::cout << "q.use_count(): " << q.use_count() << std::endl;
    }
    return 0;
}

// Unit Tests
TEST_CASE("TimedSharedPtr access after creation") {
    TimedSharedPtr<int> p(new int(42), 3);
    CHECK(p.get() != nullptr);
    CHECK(p.use_count() == 1);
}

TEST_CASE("TimedSharedPtr basic expiration") {
    TimedSharedPtr<Node> myNode(new Node(7), 1);
    TimedSharedPtr<Node> myOtherNode = myNode;
    sleep(1);
    CHECK(myNode.get() == nullptr);
    CHECK(myNode.use_count() == 2);
}

TEST_CASE("TimedSharedPtr copy constructor") {
    TimedSharedPtr<int> p(new int(5), 2);
    TimedSharedPtr<int> q = p;
    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
    CHECK(p.get() != nullptr);
    CHECK(q.get() != nullptr);
}

TEST_CASE("TimedSharedPtr expiration") {
    TimedSharedPtr<int> p(new int(10), 1);
    sleep(2);
    CHECK(p.get() == nullptr);
}

TEST_CASE("TimedSharedPtr use_count with 1000ms") {
    TimedSharedPtr<int> p(new int(99));
    CHECK(p.use_count() == 1);
    TimedSharedPtr<int> q = p;
    CHECK(p.use_count() == 2);
}

// main
int main(int argc, char** argv) {
    doctest::Context context;
    int test_result = context.run(); // runs unit testing

    std::cout << std::endl;
    run_output(); // runs the demo after tests get completed
    return test_result;
}
