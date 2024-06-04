/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
#include "Structure.cpp"
using namespace std;

namespace ariel{

class Player {
public:
    string name;
    vector<ReturnRes> returnRes; // All the resources the player has
    vector<Structure> roads;
    vector<Structure> settlements;
    vector<Structure> cities;

    Player(string n) : name(n) {} // constructor
    ~Player() { // distructor
        this->name = "";
        this->returnRes.clear();
        this->roads.clear();
        this->settlements.clear();
        this->cities.clear();
    } 

    void addRoad();

    void addSettlement();

    void addCity();

    void printPlayerInfo();

    void placeRoad(places, placesNum, board);
    void placeRoad(Tile* tile1, Tile* tile2);

    void placeSettelemnt(places, placesNum, board);
    void placeSettlements(Tile* tile1, Tile* tile2, Tile* tile3);

    void placeCity(Tile* tile1, Tile* tile2, Tile* tile3);

    // void rollDice(); // Lets say it's print 4. Then, p2 gets ore from the mountations.
    
    // void placeRoad({"Forest", "Hills"}, {5, 6}, board); // p1 continues to build a road.
    
    // void trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    
    // bool endTurn(); // p1 ends his turn.
    
    // void buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    
    // void printPoints(); // p1 has 2 points because it has two settelments.
    
};
}
