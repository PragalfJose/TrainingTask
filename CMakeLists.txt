# Sample CMakeLIst file
# Specify the minimum required version of CMAKE
cmake_minimum_required(VERSION 3.10)

# Set c standard
set(CMAKE_C_STANDARD 11)

# Specify project name
project(ProjctConsole)

# Include directory list for headers
include_directories(${CMAKE_SOURCE_DIR}/appTimer 
                    ${CMAKE_SOURCE_DIR}/appLed
                    ${CMAKE_SOURCE_DIR}/Console
                    ${CMAKE_SOURCE_DIR}/Common)

# Search files with specific patterm (or use set function)
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/*.c"
                    "${CMAKE_SOURCE_DIR}/appTimer/*.c"
                    "${CMAKE_SOURCE_DIR}/appLed/*.c"
                    "${CMAKE_SOURCE_DIR}/Console/*.c")
# To print Somethimg
# message(STATUS "The value of MY_VARIABLE is: ${SRC_FILES}")

# Add executables with project name
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra)
set_target_properties(${PROJECT_NAME} PROPERTIES
                        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Release)

# Add executables for debug target
add_executable(PROJECT_DEBUG ${SRC_FILES})
target_compile_options(PROJECT_DEBUG PRIVATE -Wall -Werror -Wextra -g)
set_target_properties(PROJECT_DEBUG PROPERTIES
                        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Debug)