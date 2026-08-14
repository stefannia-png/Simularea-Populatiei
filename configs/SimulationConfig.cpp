#include "SimulationConfig.h"

SimulationConfig::SimulationConfig()
    : initialPopulation_(1000), birthRate_(0.02), deathRate_(0.01) {}

SimulationConfig::SimulationConfig(long long initialPopulation, double birthRate, double deathRate)
    : initialPopulation_(initialPopulation), birthRate_(birthRate), deathRate_(deathRate) {}

long long SimulationConfig::getInitialPopulation() const {
    return initialPopulation_;
}

double SimulationConfig::getBirthRate() const {
    return birthRate_;
}

double SimulationConfig::getDeathRate() const {
    return deathRate_;
}

// --- Setters ---
void SimulationConfig::setInitialPopulation(long long value) {
    initialPopulation_ = value;
}

void SimulationConfig::setBirthRate(double value) {
    birthRate_ = value;
}

void SimulationConfig::setDeathRate(double value) {
    deathRate_ = value;
}