/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;

namespace ariel{

    Board Catan::getBoard(){ // get the board of the game
        return *this->gameBoard;
    }

    vector<Player>& Catan::getPlayers(){
        return this->players;
    }

    Player Catan::ChooseStartingPlayer(){ // should print the name of the starting player

    }

    void Catan::printWinner(){ // Should print None because no player reached 10 points.
        cout << " The winner is:" << winner << endl;
    }
}
