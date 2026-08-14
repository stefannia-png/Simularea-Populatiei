#ifndef SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H
#define SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H

class SimulationConfig {
public:

    SimulationConfig();
    SimulationConfig(long long initialPopulation, double birthRate, double deathRate);

    long long getInitialPopulation() const;
    double getBirthRate() const;
    double getDeathRate() const;

    void setInitialPopulation(long long value);
    void setBirthRate(double value);
    void setDeathRate(double value);

private:
    long long initialPopulation_;
    double birthRate_;
    double deathRate_;
};

#endif //SIMULAREA_POPULATIEI_SIMULATIONCONFIG_H