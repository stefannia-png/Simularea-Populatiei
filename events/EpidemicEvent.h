//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_EPIDEMICEVENT_H
#define SIMULAREA_POPULATIEI_EPIDEMICEVENT_H

#include "Event.h"
#include "../configs/Range.h"

class EpidemicEvent : public Event {
    public:
    //lossrange e interval min max

    EpidemicEvent(Range<double> lossRange=Range<double>(8.0,18.0));
    std::string getName() const override;
    std::string apply(Population& population) const override;

private:
    Range<double> lossRange_;

};


#endif //SIMULAREA_POPULATIEI_EPIDEMICEVENT_H
