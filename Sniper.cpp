#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Sniper.hpp"
#include "Board.hpp"
using namespace std;


    void Sniper::activate(int x,int y,WarGame::Board &board1){
        int x2,y2;
        int max=0;
        int mySniper=getID();
        Soldier* chosenOne=nullptr;
        vector<std::vector<Soldier *>>board2=board1.getBoard();
        int m=board2.size();
        int n=board2[0].size();
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(board2[i][j]->getID()!=mySniper&&board2[i][j]!=nullptr&&board2[i][j]->getHP()>max){
              max=board2[i][j]->getHP();
              x2=i;
              y2=j;
              chosenOne=board2[i][j];
            }
          }
        }
        if(chosenOne!=nullptr){
          chosenOne->dmg(power);
          if(chosenOne->getHP()==0){
            board2[x2][y2]=nullptr;
             cout<< "Sniper["<< x <<"]["<<y<<"] is attacking soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
            cout << "Sniper["<< x <<"]["<<y<<"] killed soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
          }else{
            cout<< "Sniper["<< x <<"]["<<y<<"] is attacking soldier at ["<<x2<<"]["<<y2<<"]"<<endl;
          }
        }
    }
    void Sniper::printSoldier(){
        cout << "Sniper: ";
        Soldier::printSoldier();
    }
