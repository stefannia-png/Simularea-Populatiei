//
// Created by Stefa on 13/08/2026.
//

#include "EpidemicEvent.h"

#include "EpidemicEvent.h"
#include <sstream>
#include <iomanip>


EpidemicEvent::EpidemicEvent(Range<double> lossRange) : lossRange_(lossRange) {}

std::string EpidemicEvent::getName() const {
    return "Epidemie";
}

std::string EpidemicEvent::apply(Population& population) const {
    double lossPercent = lossRange_.getRandomValue(); // ex: val random de 12.3%

    population.adjustByPercent(-lossPercent); // adica scadem populatia

    std::ostringstream description;
    description << std::fixed << std::setprecision(1);
    description << "Epidemie: populatia a scazut cu " << lossPercent << "%";
    return description.str();
}
