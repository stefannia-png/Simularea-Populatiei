//
// Created by Stefa on 13/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_YEARRECORD_H
#define SIMULAREA_POPULATIEI_YEARRECORD_H

#include <string>
#include <iostream>
class YearRecord {
public:
    YearRecord(int year, long long population, std::string eventDescription = "");

    int getYear() const;
    long long getPopulation() const;
    const std::string& getEventDescription() const;
    bool hasEvent() const;

    // Suprascriere operator<< pentru afisare directa (Lab: supraincarcarea
    // operatorilor). Ex: std::cout << yearRecord;
    friend std::ostream& operator<<(std::ostream& out, const YearRecord& record);

private:
    int year_;
    long long population_;
    std::string eventDescription_; // gol daca nu s-a intamplat niciun eveniment
};

#endif //SIMULAREA_POPULATIEI_YEARRECORD_H
