#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

    class FootSoldier: public Soldier{
        
        public:
            FootSoldier(uint nplayer): Soldier(nplayer,100,10){}
            void activate(int x, int y, WarGame::Board &board1) override;
            void printSoldier() override;

    };