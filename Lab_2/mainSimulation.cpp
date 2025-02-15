#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "BalancedLists.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

TEST_CASE("EMPTY VECTOR") {
    auto arr = createInitialList(0);
    CHECK(arr.empty());
}

TEST_CASE("NORMAL VECTOR") {
    auto arr = createInitialList(2);
    std::vector<int> expected = {1, 1, -1, -1};
    CHECK(arr == expected);
}

TEST_CASE("NON MIXED VECTOR") {
    std::vector<int> arr = {1, 1, -1, -1};
    CHECK(!hasMixedPrefixSums(arr));
}

TEST_CASE("MIXED VECTOR") {
    std::vector<int> arr = {-1, 1, 1, -1};
    CHECK(hasMixedPrefixSums(arr));
}

int main(int argc, char** argv) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run();
    if (context.shouldExit()) {
        return res;
    }
    int n, trials;
    std::cout << "Enter the number of pairs (n): ";
    std::cin >> n;
    std::cout << "Enter the number of trials: ";
    std::cin >> trials;
    posNeg(trials, n);
    return res;
}
