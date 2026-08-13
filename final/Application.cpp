#include "Application.h"
#include "../configs/ConfigPresets.h"
#include "../eventManager/EventManager.h"
#include "../save/ReportGenerator.h" //?unde plm e asta
#include "../eventManager/TurnCommandParser.h"
#include <iostream>
#include "../display/consoleDisplay.h"

void Application::run() {
    ConsoleDisplay::printWelcomeMessage();

    // Pasul 1: alegem configuratia initiala (preset sau custom)
    initialConfig_ = chooseInitialConfig();

    // Pasul 2: cream motorul de simulare, cu evenimentele implicite
    // (Epidemie, Baby Boom, Dezastru Natural) inregistrate automat.
    engine_ = std::make_unique<SimulationEngine>(initialConfig_, createDefaultEventManager());

    // Pasul 3: rulam bucla principala de ture pana la 'q' sau game over
    ConsoleDisplay::printTurnInstructions();
    runMainLoop();

    // Pasul 4: afisam raportul final
    ReportGenerator::printFinalReport(engine_->getHistory(), initialConfig_);
}

SimulationConfig Application::chooseInitialConfig() const {
    ConsoleDisplay::printSetupMenu();
    int choice = inputHandler_.readSetupChoice();

    if (choice == 1) {
        // Model Implicit (Preset)
        return Configpresets::getDefaultConfig();
    }

    // Model Personalizat (Custom Input)
    return inputHandler_.readCustomConfig();
}

void Application::runMainLoop() {
    while (true) {
        // Verificam game over-ul INAINTE de a mai cere o comanda
        if (engine_->isGameOver()) {
            ConsoleDisplay::printGameOverMessage();
            return;
        }

        std::cout << "\n[An curent: " << engine_->getCurrentYear()
                  << " | Populatie: " << engine_->getPopulation().getCurrentPopulation()
                  << "] Comanda ta: ";

        std::string rawInput = inputHandler_.readTurnCommand();
        ParsedCommand command = TurnCommandParser::parse(rawInput);

        switch (command.type) {
            case CommandType::QUIT:
                return; // iesim din bucla -> se afiseaza raportul final in run()

            case CommandType::ADVANCE_YEARS: {
                std::vector<YearRecord> newRecords = engine_->advanceYears(command.years);
                for (const auto& record : newRecords) {
                    ConsoleDisplay::printYearResult(record);
                }
                break;
            }

            case CommandType::INVALID:
            default:
                ConsoleDisplay::printInvalidInputMessage();
                break;
        }

        // Daca populatia s-a stins in timpul avansului de mai multi ani,
        // bucla urmatoare va detecta acest lucru la inceputul iteratiei.
    }
}