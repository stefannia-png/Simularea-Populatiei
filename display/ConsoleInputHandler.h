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
        int choice = 0;

        while (true) {
            std::cin >> choice;

            if (!std::cin.fail() && (choice == 1 || choice == 2)) {
                std::cin.ignore(10000, '\n');
                return choice;
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Optiune invalida! Te rog alege 1 sau 2: ";
        }
    }

    SimulationConfig readCustomConfig() const {
        SimulationConfig config;

        long long initialPop = 0;
        double birthRate = 0.0;
        double deathRate = 0.0;

        std::cout << "====================================\n";
        std::cout << "  CONFIGURARE CIVILIZATIE CUSTOM\n";
        std::cout << "====================================\n";

        std::cout << "\n Introduce populatia initiala (ex: 1000): ";
        std::cin >> initialPop;

        std::cout << "Introduce rata natalitatii (ex: 0.05 pentru 5%): ";
        std::cin >> birthRate;

        std::cout << "Introduce rata mortalitatii (ex: 0.02 pentru 2%): ";
        std::cin >> deathRate;

        std::cin.ignore(10000, '\n');

        config.setInitialPopulation(initialPop);
        config.setBirthRate(birthRate);
        config.setDeathRate(deathRate);

        return config;
    }

    std::string readTurnCommand() const {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }
};


#endif //SIMULAREA_POPULATIEI_CONSOLEINPUTHANDLER_H
