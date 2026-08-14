//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H
#define SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H


#include <string>

enum class CommandType {
    ADVANCE_YEARS, // Numar de ani (>= 1)
    QUIT,          // Salire / Inchidere
    INVALID        // Input gresit
};

struct ParsedCommand {
    CommandType type = CommandType::INVALID;
    int years = 0;
};

class TurnCommandParser {
public:
    static ParsedCommand parse(const std::string& rawInput);
};

#endif //SIMULAREA_POPULATIEI_TURNCOMMANDPARSER_H
