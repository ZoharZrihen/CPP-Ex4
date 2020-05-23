#pragma once
#include <string>
#include <vector>
#include <stdexcept>

namespace WarGame{
    class Soldier{
        protected:
            uint nplayer;
            uint Health; // starting hp
            int hp; //current hp
            uint power;
        public:
            Soldier(uint id,uint hpoints,uint p): nplayer(id), Health(hpoints),hp(hpoints),power(p){}
            double distance();
            void Heal(uint points);
            void dmg(uint points);
            virtual void activate()=0;
            virtual void printSoldier();
            int getID(){return nplayer;}
            void move();
            
    };
}// namespace wargame