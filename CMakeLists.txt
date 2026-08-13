cmake_minimum_required(VERSION 4.3)
project(Simularea_Populatiei)

set(CMAKE_CXX_STANDARD 20)

add_executable(Simularea_Populatiei
        final/Main.cpp
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
        events/NaturalDisasterEvent.h
        eventManager/EventManager.cpp
        eventManager/EventManager.h
        eventManager/TurnCommandParser.cpp
        eventManager/TurnCommandParser.h
        eventManager/GameOverController.cpp
        eventManager/GameOverController.h
        simulare/SimulationEngine.cpp
        simulare/SimulationEngine.h
        save/YearRecord.cpp
        save/YearRecord.h
        save/SimulationHistory.cpp
        save/SimulationHistory.h
        final/Application.cpp
        final/Application.h

        display/ConsoleDisplay.h
        display/ConsoleInputHandler.h
        save/ReportGenerator.h
        display/TextGenerator.h)
