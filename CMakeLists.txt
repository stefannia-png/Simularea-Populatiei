cmake_minimum_required(VERSION 4.3)
project(Simularea_Populatiei)

set(CMAKE_CXX_STANDARD 20)

add_executable(Simularea_Populatiei main.cpp
        cmake-build-debug/configs/Range.h
        cmake-build-debug/configs/RandomGenerator.cpp
        cmake-build-debug/configs/RandomGenerator.h
        cmake-build-debug/configs/SimulationConfig.cpp
        cmake-build-debug/configs/SimulationConfig.h
        cmake-build-debug/configs/Configpresets.cpp
        cmake-build-debug/configs/Configpresets.h
        cmake-build-debug/model/NatalityCalculator.cpp
        cmake-build-debug/model/NatalityCalculator.h
        cmake-build-debug/model/MortalityCalculator.cpp
        cmake-build-debug/model/MortalityCalculator.h
        cmake-build-debug/model/Population.cpp
        cmake-build-debug/model/Population.h)
