# Specify the minimum required version of CMAKE
cmake_minimum_required(VERSION 3.10)

# Set c standard
set(CMAKE_C_STANDARD 11)

# Specify project name
project(ProjctConsole)

include(ExternalProject)

# Linux Build
ExternalProject_Add(Native
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/GCCBuild
    BINARY_DIR ${CMAKE_BINARY_DIR}/GCCBuild
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND ""  # Skip install step
)

# Raspberry Pi Cross-Compilation
ExternalProject_Add(RPi
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/RPiBuild
    BINARY_DIR ${CMAKE_BINARY_DIR}/RPiBuild
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND "" 
)

# Group both targets under one
add_custom_target(AllTargets ALL
    DEPENDS Native RPi
)