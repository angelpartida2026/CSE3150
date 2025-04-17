#include "fraction.h"
#include "bigint.h"

std::pair<bigint, bigint> product(std::pair<bigint, bigint> a, std::pair<bigint, bigint> b) {
    return {a.first * b.first, a.second * b.second};
}

std::pair<bigint, bigint> sum(std::pair<bigint, bigint> a, std::pair<bigint, bigint> b) {
    bigint numerator = a.first * b.second + b.first * a.second;
    bigint denominator = a.second * b.second;
    return {numerator, denominator};
}

