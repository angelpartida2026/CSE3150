#ifndef BALANCEDLISTS_H
#define BALANCEDLISTS_H

#include <vector>

std::vector<int> createInitialList(int n);
void fisherYatesShuffle(std::vector<int>& vec);
bool isWellBalanced(const std::vector<int>& vec);
void runUnitTests();
#endif
