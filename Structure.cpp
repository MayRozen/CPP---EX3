/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
using namespace std;

namespace ariel{
class structure { // Abstruct class
public:
    string name;
    vector<ReturnRes> resources; // The resources we need for build the structure


    structure(string n, vector<ReturnRes> r) : name(n), resources(r) {}

    virtual ~structure();
    
};

class road : public structure { // Requires: Brick & Lumber
public:
    road() : structure("Road", {ReturnRes::Brick, ReturnRes::Lumber}) {}
};

class settlement : public structure { // Requires: Brick, Lumber, Wool, & Grain
public:
    settlement() : structure("Settlement", {ReturnRes::Brick, ReturnRes::Lumber, ReturnRes::Wool, ReturnRes::Grain}) {}
};

class city : public structure { // Requires: 3 Ore & 2 Grain
public:
    city() : structure("City", {ReturnRes::Ore, ReturnRes::Ore, ReturnRes::Ore, ReturnRes::Grain, ReturnRes::Grain}) {}
};

}
