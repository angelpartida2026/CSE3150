#ifndef COSINE_DISTANCE_H
#define COSINE_DISTANCE_H

#include <vector>
#include <tuple>

double cosineDistance(const std::vector<double>& a, const std::vector<double>& b);
std::vector<std::tuple<int, int, double>> allPairwiseDistances(const std::vector<std::vector<double>>& vectors);

#endif
