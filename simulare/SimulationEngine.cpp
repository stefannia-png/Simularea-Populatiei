
#include "SimulationEngine.h"
#include "../eventManager/GameOverController.h"
#include "../display/TextGenerator.h"
#include "../configs/RandomGenerator.h"

SimulationEngine::SimulationEngine(const SimulationConfig& config, EventManager eventManager)
    : population_(config), eventManager_(std::move(eventManager)), currentYear_(0) {}

YearRecord SimulationEngine::advanceOneYear() {
    currentYear_++;

    population_.applyNaturalGrowth();

    std::string eventDescription;
    auto triggeredEvent = eventManager_.maybeTriggerEvent(population_);
    if (!triggeredEvent.empty()) {
        eventDescription = triggeredEvent;
    }

    static TextGenerator textGen;
    int numberOfLogs = RandomGenerator::randomInt(3, 7);
    for (int i = 0; i < numberOfLogs; ++i) {
        long long microChange = RandomGenerator::randomInt(-15, 15);
        population_ += microChange;

        if (!eventDescription.empty()) {
            eventDescription += "\n";
        }
        eventDescription += textGen.getRandomLog(microChange);
    }

    YearRecord record(currentYear_, population_.getCurrentPopulation(), eventDescription);
    history_.addRecord(record);

    return record;
}

std::vector<YearRecord> SimulationEngine::advanceYears(int numberOfYears) {
    std::vector<YearRecord> records;

    for (int i = 0; i < numberOfYears; i++) {
        if (GameOverController::isGameOver(population_)) {
            break;
        }
        records.push_back(advanceOneYear());
    }

    return records;
}

bool SimulationEngine::isGameOver() const {
    return GameOverController::isGameOver(population_);
}