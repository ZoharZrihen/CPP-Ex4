#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include <iostream>
#include <cmath>
using namespace std;

    double Soldier::distance(int x1,int y1,int x2,int y2){
        return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    }
    void Soldier::dmg(uint points){
        hp-=points;
        if (hp<0){
            hp=0;
        }
    }
    bool Soldier::Heal(){
        if(hp!=0 && hp!=Health){
            hp=Health;
            return true;
        }
        return false;
    }

    void Soldier::printSoldier(){
        cout << nplayer << " has " << hp <<" hp " << endl;
    }
