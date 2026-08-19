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

        long long population = 0;
        double birthRate = 0.0;
        double deathRate = 0.0;

        std::cout << "====================================\n";
        std::cout << "  CONFIGURARE CIVILIZATIE CUSTOM\n";
        std::cout << "====================================\n";

        // --- Initial Population ---
        do {
            std::cout << "Introduce populatia initiala (minim 2): ";
            std::cin >> population;
            if (population < 2) {
                std::cout << "Valoare invalida! Numarul minim de locuitori este 2.\n";
            }
        } while (population < 2);

        // --- Birth Rate ---
        do {
            std::cout << "Introduce rata natalitatii (intre 0.0 si 1.0, ex: 0.05): ";
            std::cin >> birthRate;
            if (birthRate < 0.0 || birthRate > 1.0) {
                std::cout << "Valoare invalida! Rata trebuie sa fie intre 0 si 1 (0% - 100%).\n";
            }
        } while (birthRate < 0.0 || birthRate > 1.0);

        // --- Death Rate ---
        do {
            std::cout << "Introduce rata mortalitatii (intre 0.0 si 1.0, ex: 0.02): ";
            std::cin >> deathRate;
            if (deathRate < 0.0 || deathRate > 1.0) {
                std::cout << "Valoare invalida! Rata trebuie sa fie intre 0 si 1 (0% - 100%).\n";
            }
        } while (deathRate < 0.0 || deathRate > 1.0);

        std::cin.ignore(10000, '\n');

        config.setInitialPopulation(population);
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