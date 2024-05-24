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
        static catan* instance; // catan need to be as a singelton
        vector<player> players;
        Board gameBoard;
        player winner; 

        Catan(){  // constructor
            this->players;
            this->gameBoard;
            this->winner; // THere is no winner yet  
        }
        ~Catan(){ // distructor
            this->players.clear();
            this->gameBoard.clear();
            this->winner.clear();
        }
        
    public:

        static Catan* getInstance(){
            if(!instance){
                instance = new Catan();
            }
            return instance;
        }

        Board getBoard();  // get the board of the game
        Player ChooseStartingPlayer();   // should print the name of the starting player
        void printWinner(); // Should print None because no player reached 10 points.
    };

    Catan* catan::instance = nullptr;
}

#endif // CATAN_HPP
