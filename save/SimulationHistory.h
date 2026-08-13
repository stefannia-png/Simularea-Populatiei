//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H
#define SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H

#include <vector>
#include "YearRecord.h"

class SimulationHistory {
public:
    // Adauga o noua inregistrare de an la finalul istoricului
    void addRecord(const YearRecord& record);

    // Acces la toate inregistrarile (doar citire)
    const std::vector<YearRecord>& getRecords() const;

    // Numarul total de ani simulati pana acum
    int getYearsSimulated() const;

    // Populatia maxima/minima atinsa pe parcursul simularii
    long long getMaxPopulation() const;
    long long getMinPopulation() const;

    // Numarul de ani in care s-a declansat un eveniment
    int countYearsWithEvents() const;

private:
    std::vector<YearRecord> records_;
};

#endif //SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H
