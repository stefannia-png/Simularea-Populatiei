//
// Created by Stefa on 12/08/2026.
//

#include "MortalityCalculator.h"

long long MortalityCalculator::computeDeaths(long long currentPopulation, double deathRate) {
    return currentPopulation * deathRate;
}
