#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Paramedic.hpp"
#include "Board.hpp"
using namespace std;


    void Paramedic::activate(int x,int y,WarGame::Board &board1){
        int myPara=getID();
        vector<std::vector<Soldier *>>board2=board1.getBoard();
        int m=board2.size();
        int n=board2[0].size();
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(board2[i][j]->getID()==myPara&&board2[i][j]!=nullptr){
              double d=distance(x,y,i,j);
              if(d!=0 &&d<=sqrt(2)){
                  bool healed=board2[i][j]->Heal();
                  if(healed){
                      cout<< "Paramedic["<< x <<"]["<<y<<"] is healing soldier at ["<<i<<"]["<<j<<"]"<<endl;
                  }
            }
          }
        }
        }
    }
    void Paramedic::printSoldier(){
        cout << "Paramedic: ";
        Soldier::printSoldier();
    }
