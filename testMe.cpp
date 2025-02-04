#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"

bool non_negative_prefix_sum(const int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

bool non_positive_prefix_sum(const int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
        if (sum > 0) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Testing non_negative_prefix_sum") {

    SUBCASE("Empty array returns true") {
        int arr[1]; 
        CHECK(non_negative_prefix_sum(arr, 0));
    }

    SUBCASE("Valid non-negative prefix sums") {
        int arr[] = {1, -1, 1, -1};
        CHECK(non_negative_prefix_sum(arr, 4));
    }

    SUBCASE("Invalid non-negative prefix sum") {
        int arr[] = {1, -1, -1, 1};
        CHECK_FALSE(non_negative_prefix_sum(arr, 4));
    }

    SUBCASE("Edge: starts with -1") {
        int arr[] = {-1};
        CHECK_FALSE(non_negative_prefix_sum(arr, 1));
    }
}

TEST_CASE("Testing non_positive_prefix_sum") {

    SUBCASE("Empty array returns true") {
        int arr[1];
        CHECK(non_positive_prefix_sum(arr, 0));
    }

    SUBCASE("Valid non-positive prefix sums") {
        int arr[] = {-1, 1, -1, 1};
        CHECK(non_positive_prefix_sum(arr, 4));
    }

    SUBCASE("Invalid non-positive prefix sum") {
        int arr[] = {-1, 1, 1, -1};
        CHECK_FALSE(non_positive_prefix_sum(arr, 4));
    }

    SUBCASE("Edge: starts with +1") {
        int arr[] = {1};
        CHECK_FALSE(non_positive_prefix_sum(arr, 1));
    }
}
