#include "Model/Game.h"
#include <iostream>

class Controller {
    Game *m_game;

    Controller() {}

    void startGame() {
        int numPlayers = 2;
        int maxRounds = 10;
        std::cout << "Enter number of players" << std::endl;
        std::cin >> numPlayers;
        std::cout << "Enter max number of rounds" << std::endl;
        std::cin >> maxRounds;


        m_game = new Game(numPlayers);
        std::vector<std::string> names;

        for(int i = 0; i < numPlayers; i++) {
            std::cout << "Enter player " << i << " name" << std::endl;
        }

        while(!m_game->m_isGameOver) {

            for(auto &player : m_game->m_players) {
                runRound(player);
                if(m_game->m_isGameOver) {
                    break;
                }
            }
            m_game->m_numRounds++;
        }
    }

    void runRound(Player &player) {

    }
};