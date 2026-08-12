//
// Created by Stefa on 12/08/2026.
//

#include "MortalityCalculator.h"

long long MortalityCalculator::computeDeaths(long long currentPopulation, double deathRate) {
    //formula e la fel ca la natalitate doar ca e cu decese
    double deaths= static_cast<double>(currentPopulation)*deathRate;
    return static_cast<long long>(deaths);
}
