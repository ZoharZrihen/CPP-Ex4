#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

    class FootCommander: public FootSoldier{

        public:
        FootCommander(uint nplayer): FootSoldier(nplayer){
            Health+=50;
            hp+=50;
            power+=10;
            }
        void activate(int x,int y,WarGame::Board &board1) override;
        void printSoldier() override;
        
    };
