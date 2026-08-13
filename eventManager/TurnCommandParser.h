//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H
#define SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H


#include <string>

// Tipurile de comenzi posibile
enum class CommandType {
    ADVANCE_YEARS, // Numar de ani (>= 1)
    QUIT,          // Salire / Inchidere
    INVALID        // Input gresit
};

// Rezultatul parsarii
struct ParsedCommand {
    CommandType type = CommandType::INVALID;
    int years = 0;
};

class TurnCommandParser {
public:
    // Transforma textul citit de la tastatura intr-o comanda
    static ParsedCommand parse(const std::string& rawInput);
};

#endif //SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H
