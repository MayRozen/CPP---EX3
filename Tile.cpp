/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/
#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Structure.cpp"
using namespace std;


enum class ResourceType { Hills, Forest, Mountains, Fields, Pasture, Desert, Sea };

/*
Hills - produce Brick
Forest - produce Lumber
Mountains - produce Ore
Fields - produce Grain
Pasture - produce Wool
Desert - produce nothing
*/

class Tile {
public:
    ResourceType tileResource; // The type of the resource
    int number;  // The number token on the tile
    Structure* vertices[6]; // for settlements and citicies.
    Structure* edges[6]; // for roades
    Tile* neighbors[6]; // Neighboring tiles

    Tile(ResourceType resource, int num) : tileResource(resource), number(num) { // constructor
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = nullptr;
            edges[i] = nullptr;
            neighbors[i] = nullptr;
        }
    }

    ~Tile(){
        this->tileResource = ResourceType::Sea;
        this->number = 0;

        for(size_t i=0; i<6; i++){
            this->vertices[i]=nullptr;
            this->edges[i]=nullptr;
            this->neighbors[i]=nullptr;
        }
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


#endif // TILE_HPP
