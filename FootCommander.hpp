#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

    class FootCommander: public FootSoldier{

        public:
            FootCommander(uint player_number);
            void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
            uint getHealth(){return 150;}
            void print();
            ~FootCommander(){};
        
    };
