#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic{
    public:
    ParamedicCommander(uint player_number);
    void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    void print() override;
    uint getHealth(){return 200;}
    ~ParamedicCommander(){};
};