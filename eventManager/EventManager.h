//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_EVENTMANAGER_H
#define SIMULAREA_POPULATIEI_EVENTMANAGER_H


#include <vector>
#include <memory>
#include <string>
#include "../events/Event.h"

class EventManager {
public:
    EventManager(double triggerChancePercent = 25.0);

    void registerEvent(std::unique_ptr<Event> event);

    std::string maybeTriggerEvent(Population& population) const;

    double getTriggerChancePercent() const { return triggerChancePercent_; }
    void setTriggerChancePercent(double value) { triggerChancePercent_ = value; }

private:
    std::vector<std::unique_ptr<Event>> events_;
    double triggerChancePercent_;

    const Event* pickRandomEvent() const;
};

EventManager createDefaultEventManager();
#endif //SIMULAREA_POPULATIEI_EVENTMANAGER_H
