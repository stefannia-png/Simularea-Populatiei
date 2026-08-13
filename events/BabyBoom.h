//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_BABYBOOM_H
#define SIMULAREA_POPULATIEI_BABYBOOM_H



#include "Event.h"
#include "../configs/Range.h"

class BabyBoomEvent : public Event {
public:
    explicit BabyBoomEvent(Range<double> increaseRange = Range<double>(1.0, 2.5));

    std::string getName() const override;
    std::string apply(Population& population) const override;

private:
    Range<double> increaseRange_;
};


#endif //SIMULAREA_POPULATIEI_BABYBOOM_H
