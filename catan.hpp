/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>
#include <vector>
#include "player.hpp"
#include "board.hpp"
using namespace std;

namespace ariel{

    class Catan {
    private:
        static Catan* instance; // catan need to be as a singelton
        vector<Player> players;
        Board *gameBoard;
        Player *winner; 

        Catan(){  // constructor
            this->players;
            this->gameBoard;
            this->winner; // THere is no winner yet  
        }
        ~Catan(){ // distructor
            this->players.clear();
            delete this->gameBoard;
            delete this->winner;
        }
        
    public:

        static Catan* getInstance(){
            if(!instance){
                instance = new Catan();
            }
            return instance;
        }

        vector<Player>& getPlayers(); // Return this->Players
        Board getBoard();  // get the board of the game
        Player ChooseStartingPlayer();   // should print the name of the starting player
        void printWinner(); // Should print None because no player reached 10 points.
    };

    Catan* instance = nullptr;
}

#endif // CATAN_HPP
