#include "vector_utils.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<double>> readVectors(const std::string& filename) {
    std::vector<std::vector<double>> result;
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::istringstream stream(line);
        std::vector<double> vec;
        double num;
        while (stream >> num) {
            vec.push_back(num);
        }
        result.push_back(vec);
    }

    return result;
}
