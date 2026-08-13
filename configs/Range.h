//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_RANGE_H
#define SIMULAREA_POPULATIEI_RANGE_H

#include "RandomGenerator.h"

template <typename T>
class Range {
public:
    // constructor
    Range(T minValue, T maxValue)
        : minValue_(minValue), maxValue_(maxValue) {}

    T getMin() const { return minValue_; }
    T getMax() const { return maxValue_; }

    // Returneaza o valoare aleatoare din interval.
    T getRandomValue() const {
        return static_cast<T>(RandomGenerator::randomRange(
            static_cast<double>(minValue_), static_cast<double>(maxValue_)));
    }

private:
    T minValue_;
    T maxValue_;
};

#endif //SIMULAREA_POPULATIEI_RANGE_H
