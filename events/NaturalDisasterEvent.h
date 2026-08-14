//
// Created by Stefa on 13/08/2026.
//
/*
#ifndef SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H
#define SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H

#include "Event.h"
#include "../configs/Range.h"

class NaturalDisasterEvent : public Event {
public:
    NaturalDisasterEvent(Range<double> lossRange = Range<double>(30.0, 50.0));

    std::string getName() const override;
    std::string apply(Population& population) const override;

private:
    Range<double> lossRange_;
};


#endif //SIMULAREA_POPULATIEI_NATURALDISASTEREVENT_H
*/
#ifndef NATURALDISASTEREVENT_H
#define NATURALDISASTEREVENT_H

#include "Event.h"
#include "../configs/Range.h"
#include <string>

class NaturalDisasterEvent : public Event {
public:
    explicit NaturalDisasterEvent(Range<double> lossRange, std::string disasterName = "Cutremur"); // cutremur e gen defaultul

    std::string getName() const override;
    std::string apply(Population& population) const override;

private:
    Range<double> lossRange_;
    std::string name_;
};

#endif