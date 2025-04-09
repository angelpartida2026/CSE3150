#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "vector_utils.h"
#include "cosine_distance.h"

#include <iostream>
#include <cmath>
#include <vector>

void runCosineDistanceApp() {
    std::vector<std::vector<double>> vectors = readVectors("vectors.txt");

    if (vectors.size() < 2) {
        std::cout << "Need at least 2 vectors to compare.\n";
        return;
    }

    std::vector<std::tuple<int, int, double>> results = allPairwiseDistances(vectors);

    std::cout << "\nCosine Distances (sorted by closeness):\n";
    for (auto [i, j, dist] : results) {
        std::cout << i << " " << j << " cos dist = " << dist << "\n";
    }
}

int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run(); 

    if (context.shouldExit()) {
        return res; 
    }

    runCosineDistanceApp();
    return res;
}

TEST_CASE("Cosine Distance Tests") {
    SUBCASE("Same vector") {
        std::vector<double> a = {1.0, 2.0, 3.0};
        CHECK(cosineDistance(a, a) == doctest::Approx(0.0));
    }

    SUBCASE("Different vectors") {
        std::vector<double> a = {1.0, 1.0, 1.0};
        std::vector<double> b = {1.0, 1.0, 0.0};
        double expected = 1.0 - (2.0 / (std::sqrt(3) * std::sqrt(2)));
        CHECK(cosineDistance(a, b) == doctest::Approx(expected).epsilon(0.001));
    }

    SUBCASE("Orthogonal vectors, when dot = 0") {
        std::vector<double> a = {1.0, 0.0};
        std::vector<double> b = {0.0, 1.0};
        CHECK(cosineDistance(a, b) == doctest::Approx(1.0));
    }

    SUBCASE("Opposite vectors") {
        std::vector<double> a = {1.0, 0.0};
        std::vector<double> b = {-1.0, 0.0};
        CHECK(cosineDistance(a, b) == doctest::Approx(2.0));
    }

    SUBCASE("Negative values") {
        std::vector<double> a = {-1.0, -2.0};
        std::vector<double> b = {-2.0, -4.0};
        CHECK(cosineDistance(a, b) == doctest::Approx(0.0));
    }

    SUBCASE("Zero vector") {
        std::vector<double> a = {0.0, 0.0};
        std::vector<double> b = {1.0, 1.0};
        CHECK(std::isnan(cosineDistance(a, b)));
    }
}
