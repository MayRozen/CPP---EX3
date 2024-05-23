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

    class catan {
    private:
        static catan* instance; // catan need to be as a singelton
        vector<player> players;
        Board gameBoard;
        player winner = 0; // THere is no winner yet

        catan(){  // constructor
            
        }
        ~catan(){ // distructor

        }
        
    public:

        static catan* getInstance(){
            if(!instance){
                instance = new catan();
            }
            return instance;
        }

        Board getBoard();  // get the board of the game
        ChooseStartingPlayer();   // should print the name of the starting player
        printWinner(); // Should print None because no player reached 10 points.
    };

    catan* catan::instance = nullptr;
}

#endif // CATAN_HPP