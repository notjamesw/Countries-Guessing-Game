#include "Country.h"
#include <iostream>

void Country::addNickname(std::string const nickname) {
    m_nicknames.emplace_back(nickname);
}

void Country::addNicknames(std::vector<std::string> & nicknames) {
    m_nicknames.reserve(m_nicknames.size() + nicknames.size());
    m_nicknames.insert(m_nicknames.end(), nicknames.begin(), nicknames.end());
}

void Country::printCountry() {
    std::cout << "Rank: " << m_rank << " ";
    std::cout << "Name: " << m_name << " ";
    std::cout << "Population: " << m_population << " ";
    std::cout << "WorldShare: " << m_worldShare << " ";
    std::cout << "areaKm2: " << m_areaKm2 << std::endl;
}