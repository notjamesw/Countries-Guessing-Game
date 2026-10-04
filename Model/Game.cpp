#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>

// controller will pass a vector of player names
void Game::createPlayers(vector<string> names) {
    for(int i = 0; i < m_numPlayers; i++) {
        m_players.emplace_back(names[i]);
        std::cout << "Added Player " << i << ": " << names[i] << std::endl;
    }
}

void Game::loadCountries() {
    // could do 2 steps, first step to load from the txt file, second to add nicknames

    // load countries from txt file (semicolon separated file)
    std::ifstream countriesFile("countries.txt");
    if(!countriesFile) {
        std::cerr << "Could not open the countries file" << std::endl;
        return;
    }

    string row;
    while(std::getline(countriesFile, row)) {
        // std::cout << "Processing line:" << row << std::endl;
        std::stringstream rowStream(row);
        string cell;

        int rank;
        string name;
        int population;
        float worldShare;
        int areaKm2;

        for(int i = 0; i < 5; i++) {
            std::getline(rowStream, cell, ';');
            switch(i) {
                case 0:
                    rank = stoi(cell);
                    // std::cout << cell << " ";
                    break;
                case 1:
                    name = cell;
                    // std::cout << cell << " ";
                    break;
                case 2:
                    population = stod(cell);
                    // std::cout << cell << " ";
                    break;
                case 3:
                    if(!cell.empty()) {
                        cell.pop_back();
                    } else {
                        std::cerr << "Error reading world share value" << std::endl;
                        return;
                    }
                    worldShare = stof(cell);
                    // std::cout << cell << " ";
                    break;
                case 4:
                    // std::cout << cell << "\n";
                    areaKm2 = stoi(cell);
                    break;
            }
        }
        m_countries.emplace_back(name, rank, population, worldShare, areaKm2);
        for(char &c: name) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        // std::cout << name << std::endl;
        m_hashmap[name] = m_countries.back();
        // Country curr(name, rank, population, worldShare, areaKm2);
        // curr.printCountry();
        // std::cout << "added country" << std::endl;
    }

}

bool Game::checkAnswer(string input) {
    for(char &c: input) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    if(auto it = m_hashmap.find(input); it!=m_hashmap.end()) {
        Country country = it->second;
        if(m_guessed[country.m_rank-1]) {
            // already guessed
            cout << "already guessed" << endl;
            return false;
        } else {
            m_guessed[country.m_rank-1] = true;
            return true;
        }
    }
    return false;
}

bool Game::checkGameOver() {
    if(m_playersRemaining == 1) {
        m_isGameOver = true;
    }
    return m_isGameOver;
}