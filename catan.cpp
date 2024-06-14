/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <vector>
#include "player.hpp"
#include "board.hpp"
#include "catan.hpp"
using namespace std;

Catan* Catan::instance = nullptr;

void Catan::initializationReturnRes(Player& p){
    p.returnRes.push_back(ReturnRes::Brick); // For road
    p.returnRes.push_back(ReturnRes::Lumber);
    p.returnRes.push_back(ReturnRes::Brick); // For settlement
    p.returnRes.push_back(ReturnRes::Lumber);
    p.returnRes.push_back(ReturnRes::Wool);
    p.returnRes.push_back(ReturnRes::Grain);
    p.returnRes.push_back(ReturnRes::Brick); // For road
    p.returnRes.push_back(ReturnRes::Lumber);
    p.returnRes.push_back(ReturnRes::Brick); // For settlement
    p.returnRes.push_back(ReturnRes::Lumber);
    p.returnRes.push_back(ReturnRes::Wool);
    p.returnRes.push_back(ReturnRes::Grain);
}

void Catan::printPlayers() const {
    for (auto& player : players) {
        cout << player.name << endl;
    }
}

vector<Player> Catan::getPlayers(){ // Return this->Players
    return this->players;
}
        
Board Catan::getBoard(){ // get the board of the game
    return *this->gameBoard;
}
        
Player Catan::ChooseStartingPlayer(){ // should print the name of the starting player
    if (!players.empty()) {
        cout << "The starting player is: " << players[0].name << endl;
        return this->players[0];
    } else {
        cout << "No players available." << endl;
    }
    Player p("");
    return p; // Return an empty player object
}

Player Catan::getWinner(){
    for(size_t i=0; i<this->players.size(); i++){
        if(this->players[i].sumPoints >= 10){ // For winning -> 10 or more points
            return this->players[i];
        }
    }
    return Player(""); // Return an empty player object
}

void Catan::printWinner(){ // Should print None because no player reached 10 points.
    cout << " The winner is:" << getWinner().name << endl;
}
