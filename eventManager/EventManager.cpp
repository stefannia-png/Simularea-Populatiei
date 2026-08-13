#include "EventManager.h"
#include "../configs/RandomGenerator.h"
#include "../events/EpidemicEvent.h"
#include "../events/BabyBoom.h"
#include "../events/NaturalDisasterEvent.h"

EventManager::EventManager(double triggerChancePercent)
    : triggerChancePercent_(triggerChancePercent) {}

void EventManager::registerEvent(std::unique_ptr<Event> event) {
    if (event) {
        events_.push_back(std::move(event));
    }
}


const Event* EventManager::pickRandomEvent() const {
    if (events_.empty()) {
        return nullptr;
    }

    // Se alege un eveniment aleator din vector
    int index = RandomGenerator::randomInt(0, static_cast<int>(events_.size()) - 1);
    return events_[index].get();
}

std::string EventManager::maybeTriggerEvent(Population& population) const {
    // Verificam daca se declanseaza un eveniment anul acesta
    if (RandomGenerator::randomRange(0.0, 100.0) > triggerChancePercent_) {
        return ""; // Nu s-a declanșat evenimentul anul acesta
    }

    const Event* chosenEvent = pickRandomEvent();
    if (chosenEvent == nullptr) {
        return "";
    }

    return chosenEvent->apply(population);
}

EventManager createDefaultEventManager() {
    EventManager manager(25.0);

    manager.registerEvent(std::make_unique<EpidemicEvent>());
    manager.registerEvent(std::make_unique<BabyBoomEvent>());
    manager.registerEvent(std::make_unique<NaturalDisasterEvent>());

    return manager;
}