#include <iostream>
#include "Permutation.h"

int main() {
    Permutation permutation;
    permutation.setValue(9);
    std::cout << "Permutation value is now " << Permutation::value << std::endl;
    return 0;
}
