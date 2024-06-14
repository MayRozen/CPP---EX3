/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory> // for std::unique_ptr
#include "DevelopmentCard.hpp"

using namespace std;
class Catan;
class DevelopmentCard;

class Player {
public:
    string name;
    vector<ReturnRes> returnRes; // All the resources the player has
    vector<Structure> roads;
    vector<Structure> settlements;
    vector<Structure> cities;
    vector<DevelopmentCard*> DevelopmentCards;
    int sumOfKnights;
    int sumPoints;
    bool turn = true; // When it is the player's turn -> true

    Player(string n) : name(n) {} // constructor
    ~Player() { // distructor
        this->name = "";
        this->returnRes.clear();
        this->roads.clear();
        this->settlements.clear();
        this->cities.clear();
        this->DevelopmentCards.clear();
        this->sumPoints = 0;
        this->sumOfKnights = 0;
        this->turn = false;
    } 

    string Resto_string(ReturnRes res);
    ReturnRes fromStringToRes(string st1);

// -----------------------------Structure-----------------------------
    void addRoad();

    void addSettlement();

    void addCity();

    void printPlayerInfo();

    void placeRoad(vector<string> places, vector<int> placesNum); // p1 continues to build a road.
    void placeRoad(Tile* tile1, Tile* tile2);

    bool hasRoadBetween(Tile* tile1, Tile* tile2);
    bool canPlaceSettlement(Tile* tile1, Tile* tile2);

    bool canPlaceSettlement(Tile* tile1, Tile* tile2, Tile* tile3); // Check for two consecutive roads
    void placeSettelemnts(vector<string> places, vector<int> placesNum);
    void placeSettlements(Tile* tile1, Tile* tile2, Tile* tile3);

    void placeCity(Tile* tile1, Tile* tile2, Tile* tile3);

// -----------------------------Game Logic-----------------------------
    void Player::rollDiceReturnRes(Catan* game, int num);
    void rollDice(Catan* game);
    
    void trade(Player& p2, string str1, string str2, int numOfStr1, int numOfStr2); // p1 trades 1 wood for 1 brick with p2.
    
    void endTurn();
    
    void buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    void useMonopolyCard(Catan* game, Player& p); // check all the players' ReturnRes and update them
    void useBuildingRoadsCard(Player& p);
    void useYearOfAbundanceCard(Player& p);
    void useKnightCard(Catan* game, Player& p);
    void useVictoryPointCard(Player& p);
    
    void printPoints(); // p1 has 2 points because it has two settelments.  
};

#endif // DEVELOPMENTCARD_HPP
