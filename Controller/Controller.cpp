#include "Model/Game.h"
#include "lib/lib.h"
#include <iostream>

class Controller {
    std::unique_ptr<Game> m_game;
    int m_numPlayers = 2;
    int m_maxFails = 5;
    int m_numRounds = 0;

public:
    Controller() {}
    void startGame() {
        m_numRounds = 0;
        cout << "Enter number of players (max 10)" << endl;
        cin >> m_numPlayers;
        cout << "Enter max number of fails" << endl;
        cin >> m_maxFails;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(m_numPlayers <= 0 || m_numPlayers > 10) {
            m_numPlayers = 2;
        }
        if(m_maxFails < 0) {
            m_maxFails = 5;
        }
        m_game = std::make_unique<Game>(m_numPlayers);
        std::unordered_set<string> names;
        names.reserve(m_numPlayers);

        
        for(int i = 0; i < m_numPlayers; i++) {
            string name;
            cout << "Enter player " << i << " name" << endl;
            std::getline(cin, name);
            if(name == "") {
                cout << "name cannot be empty" << endl;
                i--;
                continue;
            }
            if(!names.insert(name).second) {
                cout << "name already exists, re-enter player name" << endl;
                i--;
            }
        }
        m_game->createPlayers(vector<string>(names.begin(), names.end()));

        while(!m_game->m_isGameOver) {

            for(int i = 0; i < m_numPlayers; i++) {
                if(m_game->m_players_lost[i]) continue;

                runRound(i);
                if(m_game->m_isGameOver) {
                    break;
                }
            }
            m_game->m_numRounds++;
        }

        std::sort(m_game->m_players.begin(), m_game->m_players.end(), comparePlayers);
        int rank = 1;
        int num_players_same_score = 0;
        int prev_score = -1;
        for(auto &player : m_game->m_players) {
            if(prev_score == player.score) {
                num_players_same_score++;
            } else {
                rank += num_players_same_score;
                num_players_same_score = 1;
            }
            println("Rank {}: {}, Total Score: {}", rank, player.name, player.score);
        }
    }

private:
    // returns true if first should be ahead of second
    static constexpr bool comparePlayers(Player &player1, Player &player2) {
        if(player1.score == player2.score) {
            return player1.name < player2.name;
        }
        return player1.score > player2.score;
    }

    void runRound(int idx) {
        Player *player = &m_game->m_players[idx];
        string input;
        println("Player {} turn, enter a new country's name:", player->name);
        std::getline(cin, input);

        if(input == "quit") {
            m_game->m_isGameOver = true;
            return;
        }

        if(m_game->checkAnswer(input)) {
            println("{} is a correct guess", input);
            player->increaseScore();
        } else {
            println("{} is not a real country", input);
            player->increaseFails();
            if(player->checkLoss(m_maxFails)) {
                m_game->m_players_lost[idx] = true;
                m_game->m_playersRemaining--;
            }
        }
    }
};