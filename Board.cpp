#include "Board.hpp"

using namespace WarGame;
using namespace std;


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
        if(n>=board.size()|| m>=board[0].size()|| n<0||m<0){
            throw invalid_argument("Error: Wrong location given, out of board");
        }
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
        std::pair<int, int> next = source;
        switch(direction){
            case MoveDIR::Up:
                next.first=next.first+1;
                break;
            case MoveDIR::Down:
                next.first=next.first-1;
                break;
            case MoveDIR::Right:
                next.second=next.second+1;
                break;
            case MoveDIR::Left:
                next.second=next.second-1;
                break;
            default:
                break;
        }
        int i=next.first;
        int j=next.second;
        int size=board.size();
        if(i>=size||j>=size||i<0||j<0){
            throw invalid_argument("Error: Wrong location given, out of board");
        }
        if(board[i][j]!=nullptr){
            throw invalid_argument("Error: This place is aleardy taken by other player");
        }
        board[i][j]=s;
        board[n][m]=nullptr;
        s->activate(board,next);

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
    
