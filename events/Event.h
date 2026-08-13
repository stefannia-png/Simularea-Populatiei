//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_EVENT_H
#define SIMULAREA_POPULATIEI_EVENT_H
#include <string>
#include "../model/Population.h"

class Event {
    public:
    virtual ~Event()=default;

    virtual std::string getName() const=0; //numele evenimentului

    virtual std::string apply(Population& population) const=0; //aplica modificarea populatiei si afiseaza text despre asta

    virtual double getSelectionWeight() const {return 1.0;}
};


#endif //SIMULAREA_POPULATIEI_EVENT_H
