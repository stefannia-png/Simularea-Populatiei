//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_CONSOLEINPUTHANDLER_H
#define SIMULAREA_POPULATIEI_CONSOLEINPUTHANDLER_H

#include <iostream>
#include <string>
#include "../configs/SimulationConfig.h"

class ConsoleInputHandler {
public:
    int readSetupChoice() const {
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // curatam buffer-ul pt getline ulterior
        return choice;
    }

    SimulationConfig readCustomConfig() const { //me   ??? why was tehre a 'me' here
        // Aici pui logica ta de citire custom
        return SimulationConfig();
    }

    std::string readTurnCommand() const {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }
};


#endif //SIMULAREA_POPULATIEI_CONSOLEINPUTHANDLER_H
