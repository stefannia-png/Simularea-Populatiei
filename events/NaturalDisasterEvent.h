//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H
#define SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H

#include "Event.h"
#include "../configs/Range.h"

class NaturalDisasterEvent : public Event {
public:
    NaturalDisasterEvent(Range<double> lossRange = Range<double>(10.0, 22.0));

    std::string getName() const override;
    std::string apply(Population& population) const override;

private:
    Range<double> lossRange_;
};


#endif //SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H
