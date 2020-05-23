#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include <iostream>
using namespace std;

namespace WarGame{
    double Soldier::distance(){
        return 0.0;
    }
    void Soldier::dmg(uint points){
        hp-=points;
        if (hp<0){
            hp=0;
        }
    }
    void Soldier::Heal(uint points){
        hp+=points;
        if(hp>Health){
            hp=Health;
        }
    }
    void Soldier::move(){
        activate();
    }
    void Soldier::printSoldier(){
        cout << nplayer << "-" << hp << endl;
    }
} // namespace wargame