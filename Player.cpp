/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
#include "Structure.cpp"
#include "player.hpp"
using namespace std;

namespace ariel{

    void Player::addRoad(string name, vector<Tile> r) {
        roads.push_back(Structure(name, r));
    }

    void Player::addSettlement(string name, vector<Tile> r) {
        settlements.push_back(Structure(name, r));
    }

    void Player::addCity(string name, vector<Tile> r) {
        cities.push_back(Structure(name, r));
    }

    void Player::printPlayerInfo() {
        cout << "Roads:" << endl;
        for (const auto& road : roads) {
            cout << "Name: " << road.name << endl;
        }

        cout << "Settlements:" << endl;
        for (const auto& settlement : settlements) {
            cout << "Name: " << settlement.name << endl;
        }

        cout << "Cities:" << endl;
        for (const auto& city : cities) {
            cout << "Name: " << city.name << endl;
        }
    }
}
