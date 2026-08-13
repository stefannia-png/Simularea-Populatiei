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
        /*
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // curatam buffer-ul pt getline ulterior
        return choice;
        */
        int choice = 0;

        while (true) {
            std::cin >> choice;

            // Verificăm dacă citirea a reușit și dacă alegerea este strict 1 sau 2
            if (!std::cin.fail() && (choice == 1 || choice == 2)) {
                // Curățăm Enter-ul rămas în buffer după ce am citit 1 sau 2,
                // ca să nu afecteze citirile viitoare (ex: 'readTurnCommand' / 'getline')
                std::cin.ignore(10000, '\n');
                return choice;
            }

            // Dacă a băgat litere sau un număr invalid (ex: 3, 99, -1):
            std::cin.clear(); // Curățăm eroarea din std::cin
            std::cin.ignore(10000, '\n'); // Ștergem tot ce a scris greșit până la Enter

            std::cout << "Optiune invalida! Te rog alege 1 sau 2: ";
        }
    }

    SimulationConfig readCustomConfig() const { //me   ??? why was tehre a 'me' here
        // Aici pui logica ta de citire custom
        //return SimulationConfig();
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

        // Curatam buffer-ul tastaturii pentru a nu afecta citirile de mai tarziu
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
