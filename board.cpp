/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include "board.hpp"
using namespace std;


    vector<Tile*> Board::getTiles() const{
        return tiles;
    }

    int Board::getBoardIndex() const{
        return boardIndex;
    }

    void Board::printAsMatrix() const{ // Print the board as a matrix
        ResourceType r; 
        for(size_t i=0; i<tiles.size(); i++){
            if(i==2 || i==7 || i==13 || i==20 || i==26 || i==31 || i==34){
                cout << tiles[i] << endl;
            }
            else{
                cout << tiles[i] << " ";
            }
        }
    }

    Tile* Board::getTileAt(int boardIndex) const{
        return tiles[(size_t)boardIndex];
    }


