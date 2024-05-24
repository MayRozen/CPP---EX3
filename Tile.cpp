/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/


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
    ResourceType resource; // The type of the resource
    int number;  // The number token on the tile

    Tile(ResourceType resource, int number) : resource(resource), number(number) {}
};
