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

    class Catan {
    private:
        static Catan* instance; // Declare as static member
        vector<Player> players;
        Board *gameBoard;
        Player *winner; 
    public:

        void initializationReturnRes(Player& p);
        
        // Private constructor to prevent instantiation
        Catan(Player& p1, Player& p2, Player& p3) { // ReturnRes {Lumber, Brick, Wool, Grain, Ore};
            initializationReturnRes(p1);
            this->players.push_back(p1);

            initializationReturnRes(p2);
            this->players.push_back(p2);

            initializationReturnRes(p3);
            this->players.push_back(p3);
            
            gameBoard = new Board(); // Assume Board has a default constructor
        }

        ~Catan(){ // distructor
            this->players.clear();
            delete this->gameBoard;
        }
        
    

        static Catan* getInstance(Player& p1, Player& p2, Player& p3) {
            if (!instance) {
                instance = new Catan(p1, p2, p3);
            }
            return instance;
        }

        void printPlayers() const;

        vector<Player> getPlayers(); // Return this->Players
        
        Board getBoard(); // get the board of the game
        
        Player ChooseStartingPlayer(); // should print the name of the starting player

        Player getWinner();

        void printWinner(); // Should print None because no player reached 10 points.
    };

#endif // CATAN_HPP
