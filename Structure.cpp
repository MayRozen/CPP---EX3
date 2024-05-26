/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
using namespace std;

namespace ariel{
class Structure {
public:
    string name;
    vector<Tile> resources;

    Structure(string n, vector<Tile> r) : name(n), resources(r) {}
};
}