#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"

class SniperCommander : public Sniper{
    public:
    SniperCommander(uint player_number);
    void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    void print();
    uint getHealth(){return 120;}
     ~SniperCommander(){};
};