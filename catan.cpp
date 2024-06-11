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

        // Private constructor to prevent instantiation
        Catan(Player& p1, Player& p2, Player& p3) {
            players.push_back(p1);
            players.push_back(p2);
            players.push_back(p3);
            gameBoard = new Board(); // Assume Board has a default constructor
        }

        ~Catan(){ // distructor
            this->players.clear();
            delete this->gameBoard;
        }
        
    public:

        static Catan* getInstance(Player& p1, Player& p2, Player& p3) {
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

        vector<Player> getPlayers(){ // Return this->Players
            return this->players;
        }
        
        Board getBoard(){ // get the board of the game
            return *this->gameBoard;
        }
        
        Player ChooseStartingPlayer(){ // should print the name of the starting player
            if (!players.empty()) {
                cout << "The starting player is: " << players[0].name << endl;
                return this->players[0];
            } else {
                cout << "No players available." << endl;
            }
            return Player(""); // Return an empty player object
        }

        Player getWinner(){
            for(size_t i=0; i<this->players.size(); i++){
                if(this->players[i].sumPoints >= 10){ // For winning -> 10 or more points
                    return this->players[i];
                }
            }
            return Player(""); // Return an empty player object
        }

        void printWinner(){ // Should print None because no player reached 10 points.
            cout << " The winner is:" << getWinner().name << endl;
        }
    };

    Catan* Catan::instance = nullptr;


#endif // CATAN_HPP
