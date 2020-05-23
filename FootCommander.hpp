#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

namespace WarGame{
    class FootCommander: public FootSoldier{

        public:
        FootCommander(uint nplayer): FootSoldier(nplayer){
            Health+=50;
            hp+=50;
            power+=10;
            }
        void activate() override;
        void printSoldier() override;
        
    };
}//namespace wargame