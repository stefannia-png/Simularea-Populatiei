//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H
#define SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H


class SimulationConfig {
public:
    SimulationConfig();
    SimulationConfig(long long initialPopulation, double birthRate, double deathRate);

    long long getInitialPopulation() const;
    double getBirthRate() const;
    double getDeathRate() const;

    long long setInitialPopulation(long long value) const;
    double setBirthRate(double value) const;
    double setDeathRate(double value) const;

private:
    long long initialPopulation_;
    double birthRate_;
    double deathRate_;
};


#endif //SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H
