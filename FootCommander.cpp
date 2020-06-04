#include "FootCommander.hpp"
#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

FootCommander::FootCommander(uint player_number){
    nplayer=player_number;
    hp=150;
    power=20;
    t=Type::FootCom;
}

void FootCommander::activate(std::vector<std::vector<Soldier *>> &b, pair<int, int> location){
        Soldier *chosen=nullptr;
        std::vector<pair<int, int>> sl;
        std::vector<Soldier *> st;
        int c=b.size();
        int r=b.size();
        pair<int,int>chosenLocation;
        double min=r*c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                Soldier *temp=b[i][j];
                if(temp->getID()!=this->getID()){
                    double dis=this->distance(location.first,i,location.second,j);
                    if(dis<min){
                        min=dis;
                        chosen=temp;
                        chosenLocation={i,j};
                    }
                }
                else if(temp->getType()==Type::FootSol){
                    st.push_back(temp);
                    sl.push_back({i,j});

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
void FootCommander::print(){
    cout << "FootCommander: ";
//    Soldier::print();
}

