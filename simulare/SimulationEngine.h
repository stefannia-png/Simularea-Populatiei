//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_SIMULATIONENGINE_H
#define SIMULAREA_POPULATIEI_SIMULATIONENGINE_H

#include <vector>
#include "../model/Population.h"
#include "../eventManager/EventManager.h"
#include "../save/SimulationHistory.h"
#include "../save/YearRecord.h"


class SimulationEngine {
public:
    SimulationEngine(const SimulationConfig& config, EventManager eventManager);

    YearRecord advanceOneYear();
    std::vector<YearRecord> advanceYears(int numberOfYears);

    const Population& getPopulation() const { return population_; }
    const SimulationHistory& getHistory() const { return history_; }
    int getCurrentYear() const { return currentYear_; }
    bool isGameOver() const;

private:
    Population population_;
    EventManager eventManager_;
    SimulationHistory history_;
    int currentYear_ = 0;
};


#endif //SIMULAREA_POPULATIEI_SIMULATIONENGINE_H
