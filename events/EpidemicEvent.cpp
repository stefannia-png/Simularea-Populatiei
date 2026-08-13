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

    //
    long long current = population.getCurrentPopulation();
    long long victims = static_cast<long long>(current * (lossPercent / 100.0));

    long long minVictims = 10;
    if (victims < minVictims) {
        victims = minVictims;
    }

    population -= victims;

    population.increaseDeathRate((lossPercent / 10.0) / 100.0);

    //population.adjustByPercent(-lossPercent); // adica scadem populatia

    //


    std::ostringstream description;
    description << std::fixed << std::setprecision(1);
    description << "\n ---- \n Epidemie: populatia a scazut cu " << lossPercent << "% \n ---- \n";
    return description.str();
}
