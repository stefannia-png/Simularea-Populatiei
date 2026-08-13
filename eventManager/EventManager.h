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
    // Constructor
    EventManager(double triggerChancePercent = 25.0);

    // Adauga un eveniment nou in lista
    void registerEvent(std::unique_ptr<Event> event);

    // Incearca sa declanseze un eveniment.
    // Returneaza textul descrierii(ex: "Epidemie: -10%" sau "" daca nu s a intamplat nimic
    std::string maybeTriggerEvent(Population& population) const;

    // Getter si setter pentru sansa
    double getTriggerChancePercent() const { return triggerChancePercent_; }
    void setTriggerChancePercent(double value) { triggerChancePercent_ = value; }

private:
    // Lista simpla de evenimente
    std::vector<std::unique_ptr<Event>> events_;
    double triggerChancePercent_;

    // Alege un eveniment aleator din lista
    const Event* pickRandomEvent() const;
};

// Functie care creeaza managerul cu evenimentele de baza
EventManager createDefaultEventManager();
#endif //SIMULAREA_POPULATIEI_EVENTMANAGER_H
