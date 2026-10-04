#pragma once
#include "Country.h"
#include "Player.cpp"
#include "lib/lib.h"

enum class guessResult {
    CORRECT,
    ALREADY_GUESSED,
    INCORRECT
};

struct Game {
    int m_numPlayers;
    int m_playersRemaining;
    vector<Player> m_players;
    vector<bool> m_players_lost;
    bool m_isGameOver;
    vector<Country> m_countries; // vector of countries, ordered by population
    vector<bool> m_guessed; // which countries have been guessed
    std::unordered_map<string, Country> m_hashmap;
    static constexpr int NUM_COUNTRIES = 195;
    int m_numRounds;

    Game(int numPlayers) : m_numPlayers(numPlayers), m_playersRemaining(numPlayers),
        m_players_lost(numPlayers, false),  m_isGameOver(false), 
        m_guessed(NUM_COUNTRIES, false), m_numRounds(0) {
        m_players.reserve(numPlayers);
        m_countries.reserve(NUM_COUNTRIES);
        loadCountries();
    }

    // create players, ask for players names
    void createPlayers(vector<string> names);

    // load countries from CSV
    void loadCountries();

    // check correctness
    bool checkAnswer(string input);

    // checks if game is over
    bool checkGameOver();
};
