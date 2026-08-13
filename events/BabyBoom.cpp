#include "BabyBoom.h"
#include <sstream>
#include <iomanip>
 
BabyBoomEvent::BabyBoomEvent(Range<double> increaseRange) : increaseRange_(increaseRange) {}
 
std::string BabyBoomEvent::getName() const {
    return "Baby Boom";
}
 
std::string BabyBoomEvent::apply(Population& population) const {
    double increasePercent = increaseRange_.getRandomValue(); // ex: 1.5%
    double increaseFraction = increasePercent / 100.0;        // convertim in fractie (0.015)
 
    population.increaseBirthRate(increaseFraction);
 
    std::ostringstream description;
    description << std::fixed << std::setprecision(1);
    description << "Baby Boom: rata natalitatii a crescut permanent cu " << increasePercent << "%";
    return description.str();
}