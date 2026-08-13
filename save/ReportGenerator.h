//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_REPORTGENERATOR_H
#define SIMULAREA_POPULATIEI_REPORTGENERATOR_H

#include <iostream>
#include "../save/SimulationHistory.h"
#include "../configs/SimulationConfig.h"

class ReportGenerator {
public:
    static void printFinalReport(const SimulationHistory& history, const SimulationConfig& config) {
        std::cout << "\n=== RAPORT FINAL ===\n";
        std::cout << "Ani simulati: " << history.getYearsSimulated() << "\n";
        std::cout << "Populatie Maxima: " << history.getMaxPopulation() << "\n";
        //std::cout << "Populatie Minima: " << history.getMinPopulation() << "\n";
        std::cout << "Ani cu evenimente: " << history.countYearsWithEvents() << "\n";
    }
};

#endif //SIMULAREA_POPULATIEI_REPORTGENERATOR_H
