#include "Game.h"
#include <iostream>
#include <fstream>

// controller will pass a vector of player names
void Game::createPlayers(std::vector<std::string> names) {
    for(int i = 0; i < numPlayers; i++) {
        players.emplace_back(names[i]);
        std::cout << "Added Player " << i << ": " << names[i] << std::endl;
    }
}

void Game::loadCountries() {
    // could do 2 steps, first step to load from the txt file, second to add nicknames

    // load countries from txt file (semicolon separated file)
    std::ifstream countriesFile("build/countries.txt");
    if(!countriesFile) {
        std::cerr << "Could not open the countries file" << std::endl;
        return;
    }

    std::string row;
    while(std::getline(countriesFile, row)) {
        std::cout << "Processing line:" << row << std::endl;
    }
}

void Game::runRound() {
    return;
}

void Game::checkAnswer() {
    return;
}