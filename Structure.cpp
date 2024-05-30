/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
using namespace std;

namespace ariel{
class Structure { // Abstruct class
public:
    string name;
    vector<ReturnRes> resources; // The resources we need for build the Structure

    Structure(string n, vector<ReturnRes> r) : name(n), resources(r) {}

    virtual ~Structure(); // distructor
    
};

class road : public Structure { // Requires: Brick & Lumber
public:
    road() : Structure("Road", {ReturnRes::Brick, ReturnRes::Lumber}) {}
};

class settlement : public Structure { // Requires: Brick, Lumber, Wool, & Grain
public:
    settlement() : Structure("Settlement", {ReturnRes::Brick, ReturnRes::Lumber, ReturnRes::Wool, ReturnRes::Grain}) {}
};

class city : public Structure { // Requires: 3 Ore & 2 Grain
public:
    city() : Structure("City", {ReturnRes::Ore, ReturnRes::Ore, ReturnRes::Ore, ReturnRes::Grain, ReturnRes::Grain}) {}
};

}
