#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


class Paramedic: public Soldier{
        
    public:
        Paramedic(){};
        Paramedic(uint nplayer);
        virtual void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
        virtual void print();
        virtual uint getHealth(){return 100;}
        virtual ~Paramedic(){};

};