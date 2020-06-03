#include <iostream>
#include "Board.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

using namespace std;

namespace WarGame{
    // operator for putting soldiers on the game-board during initialization.
    Soldier *&Board::operator[](std::pair<int,int> location){
        return board[location.first][location.second];
    }

    // operator for reading which soldiers are on the game-board.
    Soldier *Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

        int n=source.first;
        int m=source.second;
        Soldier* s=board[n][m];
        if(s==nullptr){
            throw invalid_argument("Error: No soldier in this place");
        }
        if(s->getID()!=player_number){
            throw invalid_argument("Error: This soldier belongs to the other player.");
        }
        if(s->getHP()==0){
            throw invalid_argument("Error: This soldier is dead");
        }
        switch(direction){
            case Up:
                if(n+1==board.size()){
                    throw invalid_argument("Error: Player can't move out of the board");
                }
                if(board[n+1][m]!=nullptr){
                    throw invalid_argument("Error: This location is aleardy taken by other soldier.");
                }
                board[n][m]=nullptr;
                board[n+1][m]=s;
                s->activate(n+1,m,*this);
                break;
            case Down:
                if(n-1==-1){
                    throw invalid_argument("Error: Player can't move out of the board");
                }
                if(board[n-1][m]!=nullptr){
                    throw invalid_argument("Error: This location is aleardy taken by other soldier.");
                }
                board[n][m]=nullptr;
                board[n-1][m]=s;
                s->activate(n-1,m,*this);
                break;
            case Right:
                if(m+1==board[0].size()){
                    throw invalid_argument("Error: Player can't move out of the board");
                }
                if(board[n][m+1]!=nullptr){
                    throw invalid_argument("Error: This location is aleardy taken by other soldier.");
                }
                board[n][m]=nullptr;
                board[n][m+1]=s;
                s->activate(n,m+1,*this);
                break;
            case Left:
                if(m-1==-1){
                    throw invalid_argument("Error: Player can't move out of the board");
                }
                if(board[n][m-1]!=nullptr){
                    throw invalid_argument("Error: This location is aleardy taken by other soldier.");
                }
                board[n][m]=nullptr;
                board[n][m-1]=s;
                s->activate(n,m-1,*this);
                break;
        }



        
    }

    bool Board::has_soldiers(uint player_number) const{
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!=nullptr && board[i][j]->getID()==player_number&&board[n][m]->getHP()!=0){
                    return true;
                }
            }
        }
        return false;
    }
}