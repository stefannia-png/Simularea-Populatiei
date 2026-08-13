/*
#include "SimulationEngine.h"
#include "../eventManager/GameOverController.h"
#include "../display/TextGenerator.h"

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
*/
#include "SimulationEngine.h"
#include "../eventManager/GameOverController.h"
#include "../display/TextGenerator.h"
#include "../configs/RandomGenerator.h"

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

    // Pasul 3: generare rânduri secundare (stil BitLife) și lipirea lor în descriere
    static TextGenerator textGen;
    int numberOfLogs = RandomGenerator::randomInt(3, 7); // Alege random între 3 și 7 rânduri

    for (int i = 0; i < numberOfLogs; ++i) {
        long long microChange = RandomGenerator::randomInt(-15, 15);
        population_ += microChange; // Aplicăm modificarea pe populație

        // Adăugăm fiecare linie nouă direct în textul descrierii
        if (!eventDescription.empty()) {
            eventDescription += "\n";
        }
        eventDescription += textGen.getRandomLog(microChange);
    }

    // Pasul 4: Salvăm înregistrarea exact cu constructorul tău existent (3 parametri!)
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