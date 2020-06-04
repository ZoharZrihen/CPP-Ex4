#include "SniperCommander.hpp"
#include "Board.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
SniperCommander::SniperCommander(uint player_number){
    nplayer=player_number;
    hp=120;
    power=100;
    t=Type::SniperCom;
}
void SniperCommander::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
        Soldier *chosen=nullptr;
        std::vector<pair<int, int>> sl;
        std::vector<Soldier *> st;
        int c=b.size();
        int r=b.size();
        pair<int,int>chosenLocation;
        double max=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(b[i][j]!=nullptr){
                    Soldier *temp=b[i][j];
                    if(temp->getID()!=this->getID()){
                        uint thp=temp->getHP();
                        if(thp>max){
                            max=thp;
                            chosen=temp;
                            chosenLocation={i,j};
                        }
                 }
                else if(temp->getType()==Type::Snip){
                    st.push_back(temp);
                    sl.push_back({i,j});

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
        for(int i=0;i<st.size();i++){
            st[i]->activate(b,sl[i]);
        }
}
 void SniperCommander::print(){
        cout <<"SniperCommander:";
       // Soldier::print();
    }

