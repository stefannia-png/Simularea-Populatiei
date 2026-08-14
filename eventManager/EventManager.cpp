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
    if (RandomGenerator::randomRange(0.0, 100.0) > triggerChancePercent_) {
        return "";
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


    // Cutremur
    manager.registerEvent(std::make_unique<NaturalDisasterEvent>(Range<double>(10.0, 25.0), "Cutremur"));

    // Tsunami
    manager.registerEvent(std::make_unique<NaturalDisasterEvent>(Range<double>(20.0, 45.0), "Tsunami"));

    // Erupție vulcanica
    manager.registerEvent(std::make_unique<NaturalDisasterEvent>(Range<double>(5.0, 15.0), "Eruptie Vulcanica"));

    return manager;
}