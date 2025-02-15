#include "BalancedLists.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

std::vector<int> createInitialList(int n) {
    std::vector<int> vec;
    vec.reserve(2 * n);
    for (int i = 0; i < n; ++i)
        vec.push_back(1);
    for (int i = 0; i < n; ++i)
        vec.push_back(-1);
    return vec;
}

void fisherYatesShuffle(std::vector<int>& vec) {
    int size = vec.size();
    for (int i = size - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }
}

bool hasMixedPrefixSums(const std::vector<int>& vec) {
    int prefix = 0;
    bool hasPositive = false, hasNegative = false;
    for (int num : vec) {
        prefix += num;
        if (prefix > 0) hasPositive = true;
        if (prefix < 0) hasNegative = true;
    }
    return (hasPositive && hasNegative);
}

void posNeg(int trials, int n) {
    int countMixed = 0;
    for (int i = 0; i < trials; ++i) {
        auto seq = createInitialList(n);
        fisherYatesShuffle(seq);
        if (hasMixedPrefixSums(seq))
            countMixed++;
    }
    std::cout << "Number of sequences with both positive and negative prefix sums: " << countMixed << std::endl;
    std::cout << "Total number of trials: " << trials << std::endl;
    std::cout << "Ratio: " << static_cast<double>(countMixed) / trials << std::endl;
}
