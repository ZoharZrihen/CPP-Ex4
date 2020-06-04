#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Sniper.hpp"
#include "Board.hpp"
using namespace std;


    Sniper::Sniper(uint player_number){
      nplayer=player_number;
      hp=100;
      power=50;
      t=Type::Snip;
    }

    void Sniper::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
       Soldier *chosen=nullptr;
       pair<int,int>chosenLocation;
       int r=b.size();
       int c=b.size();
       uint max=0;
       for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            if(b[i][j]!=nullptr){
              Soldier *temp=b[i][j];
              if(temp->getID()!=this->getID()){
                uint tmax=temp->getHP();
                if(tmax>max){
                  max=tmax;
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
    void Sniper::print(){
        cout << "Sniper: ";
      //  Soldier::print();
    }
