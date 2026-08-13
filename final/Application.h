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

// ============================================================================
// Application
// ----------------------------------------------------------------------------
// Clasa "de nivel superior" (top-level) care leaga toate celelalte clase
// intre ele si controleaza fluxul complet al programului:
//   1. Afiseaza mesajul de bun venit
//   2. Cere utilizatorului sa aleaga modelul (implicit sau personalizat)
//   3. Creeaza SimulationEngine cu configuratia aleasa
//   4. Ruleaza bucla principala de ture (ENTER / numar / q)
//   5. La final, afiseaza raportul complet
//
// main.cpp este intentionat FOARTE SCURT: doar creeaza un obiect Application
// si apeleaza run(). Toata logica reala e aici, ca sa fie usor de gasit si
// de modificat daca vrei sa schimbi fluxul programului.
// ============================================================================
class Application {
public:
    // Punctul de intrare in logica programului (apelat din main.cpp)
    void run();

private:
    // --- Pasii interni ai fluxului, separati in metode private pentru claritate ---

    // Cere utilizatorului sa aleaga preset/custom si construieste configuratia
    SimulationConfig chooseInitialConfig() const;

    // Ruleaza bucla principala de ture (ENTER / N / q) pana la game over sau 'q'
    void runMainLoop();

    // --- Colaboratori (celelalte clase folosite de Application) ---
    // ConsoleDisplay e o clasa complet statica (nu se instantiaza), se
    // folosesc direct metodele ei: ConsoleDisplay::printX(...)
    ConsoleInputHandler inputHandler_;    // citeste datele de la utilizator

    SimulationConfig initialConfig_;                 // configuratia cu care s-a pornit simularea
    std::unique_ptr<SimulationEngine> engine_;        // motorul simularii, creat dupa configurare
};

#endif //SIMULAREA_POPULATIEI_APPLICATION_H
