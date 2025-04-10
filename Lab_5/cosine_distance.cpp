#include "cosine_distance.h"
#include <cmath>
#include <algorithm>

double cosineDistance(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = 0.0;
    double magA = 0.0, magB = 0.0;

    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
        magA += a[i] * a[i];
        magB += b[i] * b[i];
    }

    double cosine = dot / (std::sqrt(magA) * std::sqrt(magB));
    return 1.0 - cosine;
}

std::vector<std::tuple<int, int, double>> allPairwiseDistances(const std::vector<std::vector<double>>& vectors) {
    std::vector<std::tuple<int, int, double>> results;

    for (int i = 0; i < vectors.size(); ++i) {
        for (int j = i + 1; j < vectors.size(); ++j) {
            double dist = cosineDistance(vectors[i], vectors[j]);
            results.push_back(std::make_tuple(i, j, dist));
        }
    }

    std::sort(results.begin(), results.end(), [](auto& a, auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    return results;
}
