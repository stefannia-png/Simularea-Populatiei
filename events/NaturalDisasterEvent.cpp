#include "NaturalDisasterEvent.h"
#include <sstream>
#include <iomanip>

NaturalDisasterEvent::NaturalDisasterEvent(Range<double> lossRange, std::string disasterName)
    : lossRange_(lossRange), name_(std::move(disasterName)) {}

std::string NaturalDisasterEvent::getName() const {
    return "Dezastru Natural (" + name_ + ")";
}

std::string NaturalDisasterEvent::apply(Population& population) const {
    double lossPercent = lossRange_.getRandomValue();

    population.adjustByPercent(-lossPercent);

    std::ostringstream description;
    description << std::fixed << std::setprecision(1);
    description <<" ---- \n " << "Dezastru Natural: " << name_ << ": populatia a scazut cu " << lossPercent << "% \n ----";
    return description.str();
}