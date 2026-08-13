#include "SimulationHistory.h"
#include <algorithm>
#include <limits>

void SimulationHistory::addRecord(const YearRecord& record) {
    records_.push_back(record);
}

const std::vector<YearRecord>& SimulationHistory::getRecords() const {
    return records_;
}

int SimulationHistory::getYearsSimulated() const {
    return static_cast<int>(records_.size());
}

long long SimulationHistory::getMaxPopulation() const {
    long long maxPop = std::numeric_limits<long long>::min();
    for (const auto& record : records_) {
        maxPop = std::max(maxPop, record.getPopulation());
    }
    return records_.empty() ? 0 : maxPop;
}

long long SimulationHistory::getMinPopulation() const {
    long long minPop = std::numeric_limits<long long>::max();
    for (const auto& record : records_) {
        minPop = std::min(minPop, record.getPopulation());
    }
    return records_.empty() ? 0 : minPop;
}

int SimulationHistory::countYearsWithEvents() const {
    int count = 0;
    for (const auto& record : records_) {
        if (record.hasEvent()) {
            count++;
        }
    }
    return count;
}