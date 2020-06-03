#include "FootSoldier.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include <limits.h>
#include <string>

using namespace std;

    void FootSoldier::activate(int x, int y, WarGame::Board &board1){
        int mySoldier=getID();
        int x2;
        int y2;
        double min= __DBL_MAX__;
        Soldier* chosenOne=nullptr;
        vector<std::vector<Soldier*>> board2=board1.getBoard();
        int m=board2.size();
        int n=board2[0].size();
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(board2[i][j]->getID()!=mySoldier&&board2[i][j]!=nullptr){
                    double d=distance(x,y,i,j);
                    if(d<min){
                        min=d;
                        x2=i;
                        y2=j;
                        chosenOne=board2[i][j];
                }
            }
        }
    }
    if(chosenOne!=nullptr){
        chosenOne->dmg(power);
        if(chosenOne->getHP()==0){
            board2[x2][y2]=nullptr;
            cout<< "FootSoldier["<< x <<"]["<<y<<"] is attacking soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
            cout << "FootSoldier["<< x <<"]["<<y<<"] killed soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
        }else{
            cout<< "FootSoldier["<< x <<"]["<<y<<"] is attacking soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
        }
    }
    }
    void FootSoldier::printSoldier(){
         cout<< "FootSoldier: ";
         Soldier::printSoldier();
    }

