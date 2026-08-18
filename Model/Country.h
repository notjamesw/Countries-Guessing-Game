#ifndef COUNTRY_H
#include <string>
#include <vector>

// Rank;Country;Population;WorldShare;AreaKm2 is in the file
struct Country {
    std::string m_name;
    int m_rank;
    double m_population;
    float m_worldShare;
    int m_areaKm2;
    std::vector<std::string> m_nicknames;

    Country(std::string m_name, int m_rank, double m_population, float m_worldShare, int m_areaKm2)
        : m_name(m_name), m_rank(m_rank), m_population(m_population), m_worldShare(m_worldShare), m_areaKm2(m_areaKm2), m_nicknames({}) {}
    
    Country()
        : m_name(""), m_rank(0), m_population(0), m_worldShare(0), m_areaKm2(0), m_nicknames({}) {}

    void addNickname(std::string nickname);

    void addNicknames(std::vector<std::string> & nicknames);

    void printCountry();
};

#endif