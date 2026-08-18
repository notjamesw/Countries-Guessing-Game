#ifndef COUNTRY_H
#include <string>
#include <vector>

// Rank;Country;Population;WorldShare;AreaKm2 is in the file
struct Country {
    std::string name;
    int rank;
    double population;
    float worldShare;
    int areaKm2;
    std::vector<std::string> nicknames;

    Country(std::string name, int rank, double population, float worldShare, int areaKm2)
        : name(name), rank(rank), population(population), worldShare(worldShare), areaKm2(areaKm2), nicknames({}) {}
    
    Country()
        : name(""), rank(0), population(0), worldShare(0), areaKm2(0), nicknames({}) {}

    void addNickname(std::string nickname);

    void addNicknames(std::vector<std::string> & nicknames);
};

#endif