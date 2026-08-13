#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <string>
#include <vector>
#include "../configs/RandomGenerator.h"
class TextGenerator {
private:
    std::vector<std::string> positiveTemplates_;
    std::vector<std::string> negativeTemplates_;
    std::vector<std::string> neutralTemplates_;

public:
    TextGenerator() {
        // Sabloane pozitive (crestere)
        positiveTemplates_ = {
            "O recolta bogata a stimulat cresterea populatiei cu {val} persoane.",
            "Conditiile economice bune au dus la un val de imigrari de +{val} oameni.",
            "Progresele in medicina au salvat {val} vieti in acest an.",
            "O noua asezare a fost intemeiata, adaugand {val} cetateni."
        };

        // Sabloane negative (scadere)
        negativeTemplates_ = {
            "Un val de frig extrem a provocat moartea a {val} locuitori.",
            "Rezervele de hrana au scazut, cauzand pierderea a {val} cetateni.",
            "Un incendiu intr-un oras major a ucis {val} persoane.",
            "O boala sezoniera a rapus {val} oameni."
        };

        // Sabloane neutre / evenimente de fundal (fara impact masiv pe populatie)
        neutralTemplates_ = {
            "Grupuri de cercetatori raporteaza o stabilitate a resurselor.",
            "Rutele comerciale au fost extinse in regiunile vecine.",
            "Nivelul de multumire al populatiei este moderat.",
            "Oamenii de stiinta anunta noi descoperiri in agricultura."
        };
    }

    // Genereaza un rand de text in functie de tipul de impact (+, - sau neutral)
    std::string getRandomLog(long long change) {
        std::string templateStr;

        if (change > 0) {
            int idx = RandomGenerator::randomInt(0, positiveTemplates_.size() - 1);
            templateStr = positiveTemplates_[idx];

            // Inlocuim {val} cu valoarea reala
            size_t pos = templateStr.find("{val}");
            if (pos != std::string::npos) {
                templateStr.replace(pos, 5, std::to_string(change));
            }
        } else if (change < 0) {
            int idx = RandomGenerator::randomInt(0, negativeTemplates_.size() - 1);
            templateStr = negativeTemplates_[idx];
            
            size_t pos = templateStr.find("{val}");
            if (pos != std::string::npos) {
                templateStr.replace(pos, 5, std::to_string(std::abs(change)));
            }
        } else {
            int idx = RandomGenerator::randomInt(0, neutralTemplates_.size() - 1);
            templateStr = neutralTemplates_[idx];
        }

        return "   - " + templateStr;
    }
};

#endif