#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


class Sniper: public Soldier{
        
    public:
        Sniper(uint nplayer): Soldier(nplayer,100,50){}
        void activate(int x,int y,WarGame::Board &board1) override;
        void printSoldier() override;

};