//
// Created by Stefa on 12/08/2026.
//

#ifndef SIMULAREA_POPULATIEI_CONFIGPRESETS_H
#define SIMULAREA_POPULATIEI_CONFIGPRESETS_H
#include "SimulationConfig.h"

class Configpresets {
public:
    static SimulationConfig getDefaultConfig();
private:
    Configpresets()=default; //e statica deci nu se instantiaza

};


#endif //SIMULAREA_POPULATIEI_CONFIGPRESETS_H
