#include "BalancedLists.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    runUnitTests();
    std::cout << "Balanced lists unit tests passed!" << std::endl;
    
    int n;
    std::cout << "\nEnter the number of pairs (n): ";
    std::cin >> n;
    
    int numTrials;
    std::cout << "Enter the number of trials: ";
    std::cin >> numTrials;
    
    int countValid = 0;
    int countNonNegative = 0;
    int countNonPositive = 0;
    
    for (int trial = 0; trial < numTrials; ++trial) {
        std::vector<int> sequence = createInitialList(n);
        fisherYatesShuffle(sequence);

        if (isWellBalanced(sequence)) {
            ++countValid;
            int prefix = 0;
            bool allNonNegative = true;
            bool allNonPositive = true;
            for (int num : sequence) {
                prefix += num;
                if (prefix < 0)
                    allNonNegative = false;
                if (prefix > 0)
                    allNonPositive = false;
            }
            if (allNonNegative)
                ++countNonNegative;
            if (allNonPositive)
                ++countNonPositive;
        }
    }
    
    std::cout << "\n--- Simulation Results ---" << std::endl;
    std::cout << "Total trials: " << numTrials << std::endl;
    std::cout << "Well-balanced sequences: " << countValid << std::endl;
    std::cout << "   Non-negative prefix sequences: " << countNonNegative << std::endl;
    std::cout << "   Non-positive prefix sequences: " << countNonPositive << std::endl;
    double ratio = static_cast<double>(countValid) / numTrials;
    std::cout << "Ratio of well-balanced sequences: " << ratio << std::endl;
    return 0;
}
