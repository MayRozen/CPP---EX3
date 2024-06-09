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

         // Private constructor to prevent instantiation
        Catan(const Player& p1, const Player& p2, const Player& p3) {
            players.push_back(p1);
            players.push_back(p2);
            players.push_back(p3);
            gameBoard = new Board(); // Assume Board has a default constructor
            winner = nullptr; // There is no winner yet
        }

        ~Catan(){ // distructor
            this->players.clear();
            delete this->gameBoard;
            delete this->winner;
        }
        
    public:

        // void initializePlayers(Player p1, Player p2, Player p3) {
        //     if (players.size() == 3) {
        //         cout << "Game already initialized with 3 players." << endl;
        //         return;
        //     }

        //     players.push_back(p1);
        //     players.push_back(p2);
        //     players.push_back(p3);

        //     cout << "Game initialized with 3 players." << endl;
        // }

        static Catan* getInstance(const Player& p1, const Player& p2, const Player& p3) {
            if (!instance) {
                instance = new Catan(p1, p2, p3);
            }
            return instance;
        }

        void printPlayers() const {
            for (const auto& player : players) {
                cout << player.name << endl;
            }
        }

        vector<Player>& getPlayers(); // Return this->Players
        Board getBoard();  // get the board of the game
        Player ChooseStartingPlayer();   // should print the name of the starting player
        void printWinner(); // Should print None because no player reached 10 points.
    };

    Catan* instance = nullptr;
}

#endif // CATAN_HPP
