#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic{
    public:
    ParamedicCommander(uint nplayer): Paramedic(nplayer){
        Health+=100;
        hp+=100;
    }
    void activate(int x, int y, WarGame:: Board &board1) override;
    void printSoldier() override;
};