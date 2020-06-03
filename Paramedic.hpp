#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


class Paramedic: public Soldier{
        
    public:
        Paramedic(uint nplayer): Soldier(nplayer,100){}
        void activate(int x,int y,WarGame::Board &board1) override;
        void printSoldier() override;

};