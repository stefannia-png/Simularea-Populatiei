#include "GameOverController.h"

bool GameOverController::isGameOver(const Population& population) {
    return population.isExtinct();
}