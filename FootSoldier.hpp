#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame{
    class FootSoldier: public Soldier{
        
        public:
            FootSoldier(uint nplayer): Soldier(nplayer,100,10){}
            void activate() override;
            void printSoldier() override;

    };
}// namespace wargame