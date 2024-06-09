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

        static Catan* getInstance(const Player& p1, const Player& p2, const Player& p3) {
            if (!instance) {
                instance = new Catan(p1, p2, p3);
            }
            return instance;
        }
        
        // Public method to get the singleton instance without arguments
        static Catan* getInstance() {
            return instance;
        }


        void printPlayers() const {
            for (const auto& player : players) {
                cout << player.name << endl;
            }
        }

        vector<Player> getPlayers(){ // Return this->Players
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
                return;
            }
        }

        void printWinner(){ // Should print None because no player reached 10 points.
            cout << " The winner is:" << winner << endl;
        }
    };

    // Define instance inside the Catan class
    Catan* Catan::instance = nullptr;
}

#endif // CATAN_HPP
