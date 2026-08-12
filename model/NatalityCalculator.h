//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_NATALITYCALCULATOR_H
#define SIMULAREA_POPULATIEI_NATALITYCALCULATOR_H


class NatalityCalculator {
public:
    static long long computeBirths(long long currentPopulation, double birthRate);

private:
    NatalityCalculator()=default;
};


#endif //SIMULAREA_POPULATIEI_NATALITYCALCULATOR_H
