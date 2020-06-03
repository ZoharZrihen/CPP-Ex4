#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"

class SniperCommander : public Sniper{
    public:
    SniperCommander(uint nplayer): Sniper(nplayer){
        Health+=20;
        hp+=20;
        power+=50;
    }
    void activate(int x, int y, WarGame:: Board &board1) override;
    void printSoldier() override;
};