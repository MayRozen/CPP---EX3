/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/
#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <string>
#include "Structure.cpp"


enum class ResourceType { Hills, Forest, Mountains, Fields, Pasture, Desert, Sea };

std::string to_string(ReturnRes res) {
    switch (res) {
        case ReturnRes::Lumber: return "Lumber";
        case ReturnRes::Brick: return "Brick";
        case ReturnRes::Wool: return "Wool";
        case ReturnRes::Grain: return "Grain";
        case ReturnRes::Ore: return "Ore";
        default: return "Unknown";
    }
}

ReturnRes fromStringToRes(string st1){
    ReturnRes R1;
    // ReturnRes {Lumber, Brick, Wool, Grain, Ore};
    if(st1=="Lumber"){
        R1 = ReturnRes::Lumber;
    } else if(st1=="Brick"){
        R1 = ReturnRes::Brick;
    } else if(st1=="Wool"){
        R1 = ReturnRes::Wool;
    } else if(st1=="Grain"){
        R1 = ReturnRes::Grain;
    } else if(st1=="Ore"){
        R1 = ReturnRes::Ore;
    }

    return R1;
}

/*
Hills - produce Brick
Forest - produce Lumber
Mountains - produce Ore
Fields - produce Grain
Pasture - produce Wool
Desert - produce nothing
*/
namespace ariel{
class Tile {
public:
    ResourceType tileResource; // The type of the resource
    int number;  // The number token on the tile
    vector<Structure*> vertices; // for settlements and citicies.
    vector<Structure*> edges; // for roades
    vector<Tile*> neighbors; // Neighboring tiles


    Tile(ResourceType resource, int num) : tileResource(resource), number(num),vertices(6) ,edges(6), neighbors(6) {} // constructor

    ~Tile(){
        this->tileResource = ResourceType::Sea;
        this->number = 0;
        this->vertices.clear();
        this->edges.clear();
        this->neighbors.clear();
    }
    void print() const;
};

class SeaTile : public Tile {
public:
    SeaTile() : Tile(ResourceType::Sea, 0) {}

    void print() const {
        std::cout << "Sea" << std::endl;
    }
};

class ResourceTile : public Tile {
public:
    ResourceType resource; // The Tile itself in the board

    ResourceTile(ResourceType resource, int number) : Tile(resource, number) {}

    void print() const {
        std::cout << "Resource: " << getTileName(resource) << ", Number: " << number << std::endl;
    }

    string getTileName(ResourceType resource) const {
        switch (resource) {
            case ResourceType::Hills: return "Hills";
            case ResourceType::Fields: return "Fields";
            case ResourceType::Forest: return "Forest";
            case ResourceType::Pasture: return "Pasture";
            case ResourceType::Mountains: return "Mountains";
            case ResourceType::Desert: return "Desert";
            default: return "Unknown";
        }
    }

    string getReturnResName(ReturnRes res) const {
        switch (res) {
            case ReturnRes::Lumber: return "Lumber";
            case ReturnRes::Brick: return "Brick";
            case ReturnRes::Wool: return "Wool";
            case ReturnRes::Grain: return "Grain";
            case ReturnRes::Ore: return "Ore";
            default: return "Unknown";
        }
    }
};
}

#endif // TILE_HPP
