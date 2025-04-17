#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "bigint.h"
#include "fraction.cpp"
#include <iostream>
#include <chrono>
#include <utility>
using namespace std;

TEST_CASE("Product of small bigint fractions") {
    auto result = product({2, 3}, {4, 5});
    CHECK(result.first == 8);
    CHECK(result.second == 15);

    result = product({1, 2}, {1, 2});
    CHECK(result.first == 1);
    CHECK(result.second == 4);
}

TEST_CASE("Sum of small bigint fractions") {
    auto result = sum({1, 2}, {1, 3});
    CHECK(result.first == 5);
    CHECK(result.second == 6);

    result = sum({2, 5}, {3, 5});
    CHECK(result.first == 25);
    CHECK(result.second == 25);
}

TEST_CASE("Product with large bigint values") {
    pair<bigint, bigint> a = {bigint("1000000000"), bigint("2")};
    pair<bigint, bigint> b = {bigint("3"), bigint("4")};
    auto result = product(a, b);
    CHECK(result.first == bigint("3000000000"));
    CHECK(result.second == bigint("8"));
}

TEST_CASE("Sum with large bigint values") {
    pair<bigint, bigint> a = {bigint("1000000000"), bigint("2")};
    pair<bigint, bigint> b = {bigint("1000000000"), bigint("2")};
    auto result = sum(a, b);
    CHECK(result.first == bigint("4000000000"));
    CHECK(result.second == bigint("4"));
}

template<typename Func>
void benchmark(const string& label, Func op) {
    auto start = chrono::high_resolution_clock::now();
    op();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << label << " took: " << duration.count() << " microseconds" << endl;
}

void runBenchmarks() {
    cout << "\n--- Results ---\n";

    benchmark("int pair multiplication", []() {
        pair<int, int> a = {2, 3}, b = {4, 5}, r;
        for (int i = 0; i < 10; ++i)
            r = {a.first * b.first, a.second * b.second};
    });

    benchmark("long pair multiplication", []() {
        pair<long, long> a = {2, 3}, b = {4, 5}, r;
        for (int i = 0; i < 10; ++i)
            r = {a.first * b.first, a.second * b.second};
    });

    benchmark("bigint pair multiplication", []() {
        pair<bigint, bigint> a = {2, 3}, b = {4, 5}, r;
        for (int i = 0; i < 10; ++i)
            r = {a.first * b.first, a.second * b.second};
    });
}

int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run();
    if (context.shouldExit()) return res;
    runBenchmarks();
    return res;
}
