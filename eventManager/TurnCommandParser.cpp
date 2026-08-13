//
// Created by Stefa on 13/08/2026.
//

#include "TurnCommandParser.h"
#include <cctype>

ParsedCommand TurnCommandParser::parse(const std::string& rawInput) {
    // 1. Caz linie goala (ENTER) -> 1 an
    if (rawInput.empty()) {
        return {CommandType::ADVANCE_YEARS, 1};
    }

    // 2. Caz iesire -> "q" sau "Q"
    if (rawInput == "q" || rawInput == "Q") {
        return {CommandType::QUIT, 0};
    }

    // 3. Incercam sa transformam textul in numar
    try {
        size_t parsedLength = 0;
        int years = std::stoi(rawInput, &parsedLength);

        // Verificam daca e un numar intreg valid si pozitiv (fara litere lipite de el)
        if (parsedLength == rawInput.length() && years > 0) {
            return {CommandType::ADVANCE_YEARS, years};
        }
    } catch (...) {
        // Daca std::stoi esueaza (e.g. textul nu e numar), pur si simplu trecem mai departe
    }

    // 4. Comanda invalida
    return {CommandType::INVALID, 0};
}