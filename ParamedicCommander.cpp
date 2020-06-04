#include "ParamedicCommander.hpp"
#include "Board.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

ParamedicCommander::ParamedicCommander(uint player_number){
    nplayer=player_number;
    hp=200;
    power=0;
    t=Type::ParamedicCom;
}

void ParamedicCommander::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
    Soldier *chosen;
    int x=location.first;
    int y=location.second;
    int r=b.size();
    int c=b.size();
    std::vector<Soldier *> st;
    std::vector<pair<int, int>> sl;
    int size=b.size();
    if(x+1<size){
        chosen=b[x+1][y];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if(y+1<size){
        chosen=b[x][y+1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if(x-1>=0){
        chosen=b[x-1][y];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if(y-1>=0){
        chosen=b[x][y-1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if((y-1>=0)&&(x-1>=0)){
        chosen=b[x-1][y-1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if((y+1<size)&&(x+1<size)){
        chosen=b[x+1][y+1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if((y+1<size)&&(x-1>=0)){
        chosen=b[x-1][y+1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    if((y-1>=0)&&(x+1<size)){
        chosen=b[x+1][y-1];
        if(chosen!=nullptr&&chosen->getID()==this->getID()){
            uint heal=chosen->getHealth();
            chosen->setHP(heal);

        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(b[i][j]!=nullptr){
                Soldier *temp=b[i][j];
                if(temp->getID()==this->getID()){
                    if(temp->getType()==Type::Para){
                        temp->activate(b,{i,j});
                    }
                }
            }
        }
    }
    
}
 void ParamedicCommander::print(){
        cout <<"ParamedicCommander:";
//        Soldier::print();
    }

