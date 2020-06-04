#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


class Sniper: public Soldier{
    protected:
        
    public:
        Sniper(){};
        Sniper(uint player_number);
        virtual void activate( std::vector<std::vector<Soldier *>> &b,pair<int, int> location);
        virtual void print();
        virtual uint getHealth(){return 100;}
        virtual ~Sniper(){};    

};