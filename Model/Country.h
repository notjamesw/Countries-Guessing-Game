#pragma once
#include "lib/lib.h"

// Rank;Country;Population;WorldShare;AreaKm2 is in the file
struct Country {
    string m_name;
    int m_rank;
    double m_population;
    float m_worldShare;
    int m_areaKm2;
    vector<string> m_nicknames;

    Country(string m_name, int m_rank, double m_population, float m_worldShare, int m_areaKm2)
        : m_name(m_name), m_rank(m_rank), m_population(m_population), m_worldShare(m_worldShare), m_areaKm2(m_areaKm2), m_nicknames({}) {}
    
    Country()
        : m_name(""), m_rank(0), m_population(0), m_worldShare(0), m_areaKm2(0), m_nicknames({}) {}

    void addNickname(string nickname);

    void addNicknames(vector<string> & nicknames);

    void printCountry();
};