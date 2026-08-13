//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_GAMEOVERCONTROLLER_H
#define SIMULAREA_POPULATIEI_GAMEOVERCONTROLLER_H

#include "../model/Population.h"

class GameOverController {
public:
    // Verifica daca simularea trebuie oprita ex: populatie 0
    static bool isGameOver(const Population& population);
};


#endif //SIMULAREA_POPULATIEI_GAMEOVERCONTROLLER_H
