#include "Country.h"
#include "lib/lib.h"

void Country::addNickname(string const nickname) {
    m_nicknames.emplace_back(nickname);
}

void Country::addNicknames(vector<string> & nicknames) {
    m_nicknames.reserve(m_nicknames.size() + nicknames.size());
    m_nicknames.insert(m_nicknames.end(), nicknames.begin(), nicknames.end());
}

void Country::printCountry() {
    cout << "Rank: " << m_rank << " ";
    cout << "Name: " << m_name << " ";
    cout << "Population: " << m_population << " ";
    cout << "WorldShare: " << m_worldShare << " ";
    cout << "areaKm2: " << m_areaKm2 << endl;
}