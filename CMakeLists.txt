cmake_minimum_required(VERSION 4.3)
project(Simularea_Populatiei)

set(CMAKE_CXX_STANDARD 20)

add_executable(Simularea_Populatiei main.cpp
        configs/Range.h
        configs/RandomGenerator.cpp
        configs/RandomGenerator.h
        configs/SimulationConfig.cpp
        configs/SimulationConfig.h
        configs/Configpresets.cpp
        configs/Configpresets.h
        model/NatalityCalculator.cpp
        model/NatalityCalculator.h
        model/MortalityCalculator.cpp
        model/MortalityCalculator.h
        model/Population.cpp
        model/Population.h
        events/Event.h
        events/EpidemicEvent.cpp
        events/EpidemicEvent.h
        events/BabyBoom.cpp
        events/BabyBoom.h
        events/NaturalDisasterEvent.cpp
        events/NaturalDisasterEvent.h)
