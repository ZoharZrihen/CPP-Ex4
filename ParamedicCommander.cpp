#include "ParamedicCommander.hpp"
#include "Board.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void ParamedicCommander::activate(int x, int y,WarGame::Board &board1){
    cout<<"ParamedicCommander is attacking: "<<endl;
    Paramedic::activate(x,y,board1);
    cout<<"Speical Ability: "<<endl;
    int myPC=getID();
    vector<std::vector<Soldier*>> board2 = board1.getBoard();
    int m=board2.size();
    int n=board2[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board2[i][j]->getID()==myPC && board2[i][j]!=nullptr){
                if(dynamic_cast<Paramedic*>(board2[i][j])!=nullptr &&dynamic_cast<ParamedicCommander*>(board2[i][j])==nullptr){
                     board2[i][j]->activate(i,j,board1);
                }
            }
        }
    }
}
 void ParamedicCommander::printSoldier(){
        cout <<"ParamedicCommander:";
        Soldier::printSoldier();
    }

