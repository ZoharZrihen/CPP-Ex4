#include "FootCommander.hpp"
#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

void FootCommander::activate(int x,int y,WarGame::Board &board1){
    cout << "FootCommander is attacking: "<<endl;
    cout << "Special Ability:" << endl;
    int myFC=getID();
    vector<std::vector<Soldier*>> board2 = board1.getBoard();
    int m=board2.size();
    int n=board2[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board2[i][j]->getID()==myFC && board2[i][j]!=nullptr){
                if(dynamic_cast<FootSoldier*>(board2[i][j])!=nullptr &&dynamic_cast<FootCommander*>(board2[i][j])==nullptr){
                     board2[i][j]->activate(i,j,board1);
                }
            }
        }
    }
}
void FootCommander::printSoldier(){
    cout << "FootCommander: ";
    Soldier::printSoldier();
}

