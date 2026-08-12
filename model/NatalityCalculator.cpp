//
// Created by Stefa on 12/08/2026.
//

#include "NatalityCalculator.h"

long long NatalityCalculator::computeBirths(long long currentPopulation, double birthRate) {
    //formula folosita este: nasteri= populatie * rata de natalitate
    double births= static_cast<double>(currentPopulation)*birthRate;
    return static_cast<long long>(births); //converteste tipul de date static_cast
}
