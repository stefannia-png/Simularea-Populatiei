#include "NaturalDisasterEvent.h"
#include <sstream>
#include <iomanip>
 
NaturalDisasterEvent::NaturalDisasterEvent(Range<double> lossRange) : lossRange_(lossRange) {}
 
std::string NaturalDisasterEvent::getName() const {
    return "Dezastru Natural (Cutremur)";
}
 
std::string NaturalDisasterEvent::apply(Population& population) const {
    double lossPercent = lossRange_.getRandomValue();
 
    population.adjustByPercent(-lossPercent);
 
    std::ostringstream description;
    description << std::fixed << std::setprecision(1);
    description << "Cutremur: populatia a scazut cu " << lossPercent << "%";
    return description.str();
}
 