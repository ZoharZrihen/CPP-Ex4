#ifndef SOLDIER_HPP_
#define SOLDIER_HPP_
#include <string>
#include <vector>
#include <stdexcept>

namespace WarGame{
    class Board;
}
    class Soldier{
        protected:
            uint nplayer;
            uint Health; // starting hp
            int hp; //current hp
            uint power;
        public:
            Soldier(uint id,uint hpoints,uint p=0): nplayer(id), Health(hpoints),hp(hpoints),power(p){}
            double distance(int x1,int y1,int x2,int y2);
            bool Heal();
            void dmg(uint points);
            virtual void activate(int x,int y,WarGame::Board &board1)=0;
            virtual void printSoldier();
            int getID(){return nplayer;}
            int getHP(){return hp;}
            
            
    };

#endif /* SOLDIER_HPP_ */