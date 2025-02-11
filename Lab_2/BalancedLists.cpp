#include "BalancedLists.h"
#include <cstdlib>  
#include <algorithm> 
#include <cassert>

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
    int n = vec.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }
}

bool isWellBalanced(const std::vector<int>& vec) {
    int prefix = 0;
    bool allNonNegative = true;
    bool allNonPositive = true;
    for (int num : vec) {
        prefix += num;
        if (prefix < 0)
            allNonNegative = false;
        if (prefix > 0)
            allNonPositive = false;
    }
    return (allNonNegative || allNonPositive);
}

void runUnitTests() {
    {
        std::vector<int> seq = {1, -1};
        assert(isWellBalanced(seq) && "Test 1 failed: [1, -1] should be balanced.");
    }
    {
        std::vector<int> seq = {-1, 1};
        assert(isWellBalanced(seq) && "Test 2 failed: [-1, 1] should be balanced.");
    }
    {
        std::vector<int> seq = {1, -1, -1, 1};
        assert(!isWellBalanced(seq) && "Test 3 failed: [1, -1, -1, 1] should not be balanced.");
    }
    {
        std::vector<int> seq = {1, 1, -1, -1};
        assert(isWellBalanced(seq) && "Test 4 failed: [1, 1, -1, -1] should be balanced.");
    }
}
