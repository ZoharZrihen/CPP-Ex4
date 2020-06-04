#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Paramedic.hpp"
#include "Board.hpp"
using namespace std;
    Paramedic::Paramedic(uint player_number){
      nplayer=player_number;
      hp=100;
      power=0;
      t=Type::Para;
    }

    void Paramedic::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
        int x=location.first;
        int y=location.second;
        Soldier *s;
        if(x+1<b.size()){
          s=b[x+1][y];
          if(s!=nullptr&&s->getID()==this->getID()){
              uint hptoheal=s->getHealth();
              s->setHP(hptoheal);
          }
        }
        if(x-1>=0){
          s=b[x-1][y];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
        if(y-1>=0){
          s=b[x][y-1];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
        if((y-1>=0)&&(x-1>=0)){
          s=b[x-1][y-1];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
        if((y+1<b.size())&&(x+1<b.size())){
          s=b[x+1][y+1];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
        if((y+1<b.size())&&(x-1>=0)){
          s=b[x-1][y+1];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
        if((y-1>=0)&&(x+1<b.size())){
          s=b[x+1][y-1];
          if(s!=nullptr&&s->getID()!=this->getID()){
            uint hptoheal=s->getHealth();
            s->setHP(hptoheal);
          }
        }
    }
    void Paramedic::print(){
        cout << "Paramedic: ";
//        Soldier::print();
    }
