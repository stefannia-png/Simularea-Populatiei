//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_POPULATION_H
#define SIMULAREA_POPULATIEI_POPULATION_H
#include <iostream>
#include "../configs/SimulationConfig.h"

class Population {
public:
    explicit Population(const SimulationConfig& config);

    long long getCurrentPopulation()const;
    double getBirthRate()const;
    double getDeathRate()const;

    long long applyNaturalGrowth();

    void adjustByPercent(double percent);

    void increaseDeathRate( double deltaFraction );
    void increaseBirthRate( double deltaFraction );

    bool isExtinct() const;

    Population& operator+=(long long peopleToAdd);
    Population& operator-=(long long peopleToRemove);
    friend std::ostream& operator<<(std::ostream& out, const Population& population);

private:
    long long currentPopulation_;
    double birthRate_;
    double deathRate_;

};


#endif //SIMULAREA_POPULATIEI_POPULATION_H
