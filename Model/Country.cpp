#include "Country.h"

void Country::addNickname(std::string const nickname) {
    nicknames.emplace_back(nickname);
}

void Country::addNicknames(std::vector<std::string> & nicknames) {
    this->nicknames.reserve(this->nicknames.size() + nicknames.size());
    this->nicknames.insert(this->nicknames.end(), nicknames.begin(), nicknames.end());
}