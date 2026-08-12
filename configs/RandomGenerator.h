//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_RANDOMGENERATOR_H
#define SIMULAREA_POPULATIEI_RANDOMGENERATOR_H

#include <random>
class RandomGenerator {
public:
    static double randomPercent(); //ret nr R intre 0,0 si 100,0

    static bool rollChane(double chancePercent); //procentul chancePercent e daca e true sau nu

    static double randomRange(double minValue, double maxValue);

    static int randomInt(int minValue, int maxValue);

private:
    RandomGenerator()=default; //constructor privat, clasa nu poate fi instantiata

    static std::mt19937& getEngine();
};


#endif //SIMULAREA_POPULATIEI_RANDOMGENERATOR_H
