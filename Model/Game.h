#ifndef GAME_H
#include "Country.h"
#include "Player.cpp"
#include <string>
#include <vector>
#include <map>

enum class guessResult {
    CORRECT,
    ALREADY_GUESSED,
    INCORRECT
};

struct Game {
    int m_numPlayers;
    int m_playersRemaining;
    std::vector<Player> m_players;
    bool m_isGameOver;
    std::vector<Country> m_countries;
    std::vector<bool> m_guessed;
    std::unordered_map<std::string, Country> m_hashmap;
    static constexpr int NUM_COUNTRIES = 195;
    int m_numRounds;

    Game(int numPlayers) : m_numPlayers(numPlayers), m_playersRemaining(0), 
        m_isGameOver(false), m_guessed(NUM_COUNTRIES, false), m_numRounds(0) {
        m_players.reserve(numPlayers);
        m_countries.reserve(NUM_COUNTRIES);
        loadCountries();
    }

    // create players, ask for players names
    void createPlayers(std::vector<std::string> names);

    // load countries from CSV
    void loadCountries();

    // check correctness
    bool checkAnswer(std::string input);
};

#endif