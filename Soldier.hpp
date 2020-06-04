#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;
typedef enum Type{
    FootSol,
    FootCom,
    Snip,
    SniperCom,
    Para,
    ParamedicCom
} Type;

    class Soldier{
    protected:
            uint nplayer;
            uint hp; //current hp
            uint power;
            Type t;
    public:
            Soldier();
            virtual ~Soldier(){};
            double distance(int x1,int y1,int x2,int y2){return sqrt(pow((x1-x2),2) + pow((y1-y2),2));}
            virtual void activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)=0;
            virtual void print()=0;
            uint getID(){return nplayer;}
            uint getHP(){return hp;}
            virtual uint getHealth() = 0;
            void setHP(uint nhp) { hp = nhp; };
            uint getPower(){return power;}
            Type getType(){return t;}
            
    };
