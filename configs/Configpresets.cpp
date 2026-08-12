//
// Created by Stefa on 12/08/2026.
//

#include "Configpresets.h"

SimulationConfig Configpresets::getDefaultConfig() {
    //Acesta este modelul implicit
    const long long DEFAULT_POPULATION = 1000;
    const double DEFAULT_BIRTH_RATE = 0.035;
    const double DEFAULT_DEATH_RATE = 0.020;

    return  SimulationConfig(DEFAULT_POPULATION, DEFAULT_BIRTH_RATE, DEFAULT_DEATH_RATE);
}
