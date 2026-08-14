#include "Application.h"
#include "../configs/ConfigPresets.h"
#include "../eventManager/EventManager.h"
#include "../save/ReportGenerator.h" //?unde plm e asta
#include "../eventManager/TurnCommandParser.h"
#include <iostream>
#include "../display/consoleDisplay.h"
#include <limits>

void Application::run() {
    bool restart = true;

    while (restart) {
        ConsoleDisplay::printWelcomeMessage();

        initialConfig_ = chooseInitialConfig();

        engine_ = std::make_unique<SimulationEngine>(initialConfig_, createDefaultEventManager());

        ConsoleDisplay::printTurnInstructions();
        runMainLoop();

        ReportGenerator::printFinalReport(engine_->getHistory(), initialConfig_);

        if (engine_->isGameOver()) {
            std::cout << "\nVrei sa o iei de la capat cu o alta civilizatie? (d/n): ";
            char raspuns;
            std::cin >> raspuns;

            if (raspuns == 'd' || raspuns == 'D') {
                restart = true;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                restart = false;
                std::cout << "Joc incheiat. La revedere!\n";
            }
        } else {
            restart = false; // A apasat 'q' de buna voie
        }
    }
}

SimulationConfig Application::chooseInitialConfig() const {
    ConsoleDisplay::printSetupMenu();
    int choice = inputHandler_.readSetupChoice();

    if (choice == 1) {
        // Model Implicit
        return Configpresets::getDefaultConfig();
    }
    else if (choice == 2) {
        // Model custom
        return inputHandler_.readCustomConfig();
    }
    else {
        std::cout << "Optiune invalida! Te rog alege 1 sau 2: ";
    }
}

void Application::runMainLoop() {
    while (true) {
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
                return;

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

    }

}