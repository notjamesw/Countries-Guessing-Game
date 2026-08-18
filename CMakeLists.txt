cmake_minimum_required(VERSION 4.4)
project(CountryGame)

# Force C++17 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY "Model/countries.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# Include the main directory so your compiler can easily find header (.h) files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Explicitly list all your source files with their folder paths
add_executable(CountryGame
    main.cpp
    Model/Country.cpp
    Model/Game.cpp
    Model/Player.cpp
)