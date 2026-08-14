//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H
#define SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H

#include <vector>
#include "YearRecord.h"

class SimulationHistory {
public:
    void addRecord(const YearRecord& record);

    const std::vector<YearRecord>& getRecords() const;

    int getYearsSimulated() const;

    long long getMaxPopulation() const;
    long long getMinPopulation() const;

    int countYearsWithEvents() const;

private:
    std::vector<YearRecord> records_;
};

#endif //SIMULAREA_POPULATIEI_SIMULATIONHISTORY_H
