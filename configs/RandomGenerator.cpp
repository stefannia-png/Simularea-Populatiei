//
// Created by Stefa on 12/08/2026.
//

#include "RandomGenerator.h"

std::mt19937& RandomGenerator::getEngine() {
    static std::random_device seedSource;
    static std::mt19937 engine(seedSource());
    return engine;
}

double RandomGenerator::randomPercent() {
    return randomRange(0.0,100.0);
}

bool RandomGenerator::rollChane(double chancePercent) {
    double roll=randomPercent();
    return roll<chancePercent;  //genereaza un nr si verif daca e in prag
}


double RandomGenerator::randomRange(double minValue, double maxValue) {
    std::uniform_real_distribution<double> distribution(minValue, maxValue); //obiect distribution. alege nr pe interval
    return distribution(getEngine());
}

int RandomGenerator::randomInt(int minValue, int maxValue) {
    std::uniform_int_distribution<int> distribution(minValue, maxValue);
    return distribution(getEngine());
}