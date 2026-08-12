//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_RANGE_H
#define SIMULAREA_POPULATIEI_RANGE_H

#include "RandomGenerator.h"

template <typename T>
class Range {
    Range(T min, T max) : minValue(min), maxValue(max) {} //constructor

    T getMin() const { return minValue_;} //getter, const inseamna ca nu modifica
    T getMax() const { return maxValue_;}

    T getRandomValue() const {
        double randomValue = RandomGenerator::randomRange(minValue, maxValue);  //:: e ca in jaca ex: Math.random() devine Math::random()
        return static_cast<T>(randomValue); //convertire de tip si trimite rezultat
    }

private:
    T minValue_;
    T maxValue_;
};


#endif //SIMULAREA_POPULATIEI_RANGE_H
