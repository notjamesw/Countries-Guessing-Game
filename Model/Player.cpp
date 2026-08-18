#include <string>

struct Player {
    std::string name;
    int numFails;
    int score;

    Player(std::string name) : name(name), score(0), numFails(0) {}

    void increaseScore() {
        score++;
    }

    void increaseFails() {
        numFails++;
    }

    bool checkLoss(int maxFails) {
        return numFails >= maxFails;
    }
};