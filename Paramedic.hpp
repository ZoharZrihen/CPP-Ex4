#pragma once
#include "Soldier.hpp"


class Paramedic : public Soldier{
        
public:
    Paramedic(){};
    Paramedic(uint player_number);
    virtual void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    virtual void print();
    virtual uint getHealth(){return 100;}
    virtual ~Paramedic(){};

};