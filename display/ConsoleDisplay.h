//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_CONSOLEDISPLAY_H
#define SIMULAREA_POPULATIEI_CONSOLEDISPLAY_H

#include <iostream>
#include "../save/YearRecord.h"

class ConsoleDisplay {
public:
    static void printWelcomeMessage() { std::cout << "=== SIMULATOR POPULATIE ===\n"; }
    static void printSetupMenu() { std::cout << "1. Model Implicit\n2. Model Custom\nAlege: "; }
    static void printTurnInstructions() { std::cout << "Apasa ENTER pt 1 an, scrie N pt N ani, 'q' pt iesire.\n"; }
    static void printGameOverMessage() { std::cout << "\nGAME OVER! Populatia a disparut de pe fata pamantului.\n"; }
    static void printInvalidInputMessage() { std::cout << "Comanda invalida!\n"; }
    static void printYearResult(const YearRecord& record) { std::cout << record << "\n"; }
};


#endif //SIMULAREA_POPULATIEI_CONSOLEDISPLAY_H
