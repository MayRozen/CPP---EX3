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
    vector<Structure> roads;
    vector<Structure> settlements;
    vector<Structure> cities;

    Player(string n) : name(n) {} // constructor
    ~Player() { // distructor
        this->name = "";
        this->roads.clear();
        this->settlements.clear();
        this->cities.clear();
    } 

    void addRoad(string name, vector<Tile> r);

    void addSettlement(string name, vector<Tile> r);

    void addCity(string name, vector<Tile> r);;

    void printPlayerInfo();
};
}
