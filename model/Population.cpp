//
// Created by Stefa on 12/08/2026.
//

#include "Population.h"
#include "NatalityCalculator.h"
#include "MortalityCalculator.h"
#include <algorithm>

Population::Population(const SimulationConfig& config)
    : currentPopulation_(config.getInitialPopulation()),
      birthRate_(config.getBirthRate()),
      deathRate_(config.getDeathRate()) {}

long long Population::getCurrentPopulation() const { return currentPopulation_; }
double Population::getBirthRate() const { return birthRate_; }
double Population::getDeathRate() const { return deathRate_; }

long long Population::applyNaturalGrowth() {
    long long births = NatalityCalculator::computeBirths(currentPopulation_, birthRate_);
    long long deaths = MortalityCalculator::computeDeaths(currentPopulation_, deathRate_);

    long long netChange = births - deaths;
    currentPopulation_ += netChange;

    // Populatia nu poate fi negativa
    currentPopulation_ = std::max<long long>(0, currentPopulation_);

    return netChange;
}

void Population::adjustByPercent(double percent) {
    // percent = -12.0 inseamna "scade populatia cu 12%"
    double change = static_cast<double>(currentPopulation_) * (percent / 100.0);
    currentPopulation_ += static_cast<long long>(change);
    currentPopulation_ = std::max<long long>(0, currentPopulation_);
}

void Population::increaseBirthRate(double deltaFraction) {
    birthRate_ += deltaFraction;
    birthRate_ = std::max(0.0, birthRate_); // rata nu poate fi negativa
}

void Population::increaseDeathRate(double deltaFraction) {
    deathRate_ += deltaFraction;
    deathRate_ = std::max(0.0, deathRate_);
}

bool Population::isExtinct() const {
    return currentPopulation_ <= 0;
}

Population& Population::operator+=(long long peopleToAdd) {
    currentPopulation_ += peopleToAdd;
    return *this;
}

Population& Population::operator-=(long long peopleToRemove) {
    currentPopulation_ -= peopleToRemove;
    currentPopulation_ = std::max<long long>(0, currentPopulation_);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Population& population) {
    out << "Populatie=" << population.currentPopulation_
        << " | Natalitate=" << (population.birthRate_ * 100.0) << "%"
        << " | Mortalitate=" << (population.deathRate_ * 100.0) << "%";
    return out;
}