#pragma once
#include "Soldier.hpp"

class FootSoldier: public Soldier{
        
public:
    FootSoldier(){};
    FootSoldier(uint player_number);
    virtual ~FootSoldier(){};
    virtual void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    virtual void print();
    virtual uint getHealth(){return 100;}
            

    };