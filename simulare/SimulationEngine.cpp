#include "SimulationEngine.h"
#include "../eventManager/GameOverController.h"

SimulationEngine::SimulationEngine(const SimulationConfig& config, EventManager eventManager)
    : population_(config), eventManager_(std::move(eventManager)), currentYear_(0) {}

YearRecord SimulationEngine::advanceOneYear() {
    currentYear_++;

    // Pasul 1: crestere naturala (nasteri - decese)
    population_.applyNaturalGrowth();

    // Pasul 2: posibil eveniment aleator (25% sansa implicit, vezi EventManager)
    std::string eventDescription;
    auto triggeredEvent = eventManager_.maybeTriggerEvent(population_);
    if (!triggeredEvent.empty()) {
        eventDescription = triggeredEvent;
    }

    // Pasul 3: construim si salvam inregistrarea anului in istoric
    YearRecord record(currentYear_, population_.getCurrentPopulation(), eventDescription);
    history_.addRecord(record);

    return record;
}

std::vector<YearRecord> SimulationEngine::advanceYears(int numberOfYears) {
    std::vector<YearRecord> records;

    for (int i = 0; i < numberOfYears; i++) {
        if (GameOverController::isGameOver(population_)) {
            break; // ne oprim daca populatia s-a stins deja
        }
        records.push_back(advanceOneYear());
    }

    return records;
}



bool SimulationEngine::isGameOver() const {
    return GameOverController::isGameOver(population_);
}