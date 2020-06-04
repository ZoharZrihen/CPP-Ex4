#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include <limits.h>
#include <string>

using namespace std;

    FootSoldier::FootSoldier(uint player_number){
        nplayer=player_number;
        hp=100;
        power=10;
        t=Type::FootSol;
    }

    void FootSoldier::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
        int c=b.size();
        int r=b.size();
        double min=r*c;
        Soldier *chosen=nullptr;
        pair<int,int>chosenLocation;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]!=nullptr){
                    Soldier *temp=b[i][j];
                    if(temp->getID()!=this->getID()){
                        double tmin=this->distance(location.first,i,location.second,j);
                        if(tmin<min){
                            min=tmin;
                            chosen=temp;
                            chosenLocation={i,j};
                        }
                    }
                }
            }
        }
        if(chosen!=nullptr){
            int ehp=chosen->getHP();
            int nhp=ehp-this->getPower();
            if(nhp<=0){
                b[chosenLocation.first][chosenLocation.second]=nullptr;
            }else{
                chosen->setHP(nhp);
            }
        }
    }
    void FootSoldier::print(){
         cout<< "FootSoldier: ";
       //  Soldier::print();
    }

