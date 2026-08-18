#ifndef GAME_H
#include "Country.h"
#include "Player.cpp"
#include <string>
#include <vector>

struct Game {
    int m_numPlayers;
    int m_playersRemaining;
    std::vector<Player> m_players;
    bool m_isGameOver;
    std::vector<Country> m_countries;
    int const NUM_COUNTRIES = 195;

    Game(int numPlayers) : m_numPlayers(numPlayers), m_playersRemaining(0), m_isGameOver(false) {
        m_players.reserve(numPlayers);
        m_countries.reserve(NUM_COUNTRIES);
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