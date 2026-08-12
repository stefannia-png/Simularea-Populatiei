//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_MORTALITYCALCULATOR_H
#define SIMULAREA_POPULATIEI_MORTALITYCALCULATOR_H


class MortalityCalculator {
public:
    static long long computeDeaths(long long currentPopulation, double deathRate);

private:
    MortalityCalculator()=default;
};


#endif //SIMULAREA_POPULATIEI_MORTALITYCALCULATOR_H
