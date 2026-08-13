
#include "YearRecord.h"

YearRecord::YearRecord(int year, long long population, std::string eventDescription)
    : year_(year), population_(population), eventDescription_(std::move(eventDescription)) {}

int YearRecord::getYear() const { return year_; }
long long YearRecord::getPopulation() const { return population_; }
const std::string& YearRecord::getEventDescription() const { return eventDescription_; }
bool YearRecord::hasEvent() const { return !eventDescription_.empty(); }




std::ostream& operator<<(std::ostream& out, const YearRecord& record) {
    out << "An " << record.year_ << ": Populatia la finalul anului = " << record.population_;
    if (record.hasEvent()) {
        out << "\n  [EVENIMENT: \n" << record.eventDescription_ << "]\n";
    }
    return out;
}