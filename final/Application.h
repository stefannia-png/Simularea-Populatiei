//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_APPLICATION_H
#define SIMULAREA_POPULATIEI_APPLICATION_H

#include <memory>
#include "../configs/SimulationConfig.h"
#include "../simulare/SimulationEngine.h"
#include "../display/ConsoleDisplay.h"
#include "../display/ConsoleInputHandler.h"

class Application {
public:
    void run();

private:

    SimulationConfig chooseInitialConfig() const;

    void runMainLoop();

    ConsoleInputHandler inputHandler_;

    SimulationConfig initialConfig_;
    std::unique_ptr<SimulationEngine> engine_;
};

#endif //SIMULAREA_POPULATIEI_APPLICATION_H
