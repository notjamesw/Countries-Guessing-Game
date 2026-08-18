#ifndef GAME_H
#include "Country.h"
#include "Player.cpp"
#include <string>
#include <vector>

struct Game {
    int numPlayers;
    int playersRemaining;
    std::vector<Player> players;
    bool isGameOver;
    std::vector<Country> countries;

    Game(int numPlayers) : numPlayers(numPlayers), playersRemaining(0), isGameOver(false) {
        players.reserve(numPlayers);
        loadCountries();
    }

    // create players, ask for players names
    void createPlayers(std::vector<std::string> names);

    // load countries from CSV
    void loadCountries();

    // run a round of the game
    void runRound();

    // check correctness
    void checkAnswer();
};

#endif