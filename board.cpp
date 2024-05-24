/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include "board.hpp"
#include "Tile.cpp"
using namespace std;
using namespace ariel;

class Board {
private:
    std::vector<Tile> tiles;
    // Add data structure to manage the layout of tiles

public:
    Board() {
        initialize();
    }

    void initialize() {
        // The board is arranged according to the example which in the rules book - from the left to the right.
        

        // -----------------------------Sea-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));
        tiles.push_back(Tile(ResourceType::Sea, 0));
        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------line 1-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));

        tiles.push_back(Tile(ResourceType::Mountains, 10));
        tiles.push_back(Tile(ResourceType::Pasture, 2));
        tiles.push_back(Tile(ResourceType::Forest, 9));

        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------line 2-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));

        tiles.push_back(Tile(ResourceType::Fields, 12));
        tiles.push_back(Tile(ResourceType::Hills, 6));
        tiles.push_back(Tile(ResourceType::Pasture, 4));
        tiles.push_back(Tile(ResourceType::Hills, 10));

        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------line 3-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));

        tiles.push_back(Tile(ResourceType::Fields, 9));
        tiles.push_back(Tile(ResourceType::Forest, 11));
        tiles.push_back(Tile(ResourceType::Desert, 0));
        tiles.push_back(Tile(ResourceType::Forest, 3));
        tiles.push_back(Tile(ResourceType::Mountains, 8));

        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------line 4-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));

        tiles.push_back(Tile(ResourceType::Forest, 8));
        tiles.push_back(Tile(ResourceType::Mountains, 3));
        tiles.push_back(Tile(ResourceType::Fields, 4));
        tiles.push_back(Tile(ResourceType::Pasture, 5));

        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------line 5-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));

        tiles.push_back(Tile(ResourceType::Hills, 5));
        tiles.push_back(Tile(ResourceType::Fields, 6));
        tiles.push_back(Tile(ResourceType::Pasture, 11));

        tiles.push_back(Tile(ResourceType::Sea, 0));

        // -----------------------------Sea-----------------------------
        tiles.push_back(Tile(ResourceType::Sea, 0));
        tiles.push_back(Tile(ResourceType::Sea, 0));
        tiles.push_back(Tile(ResourceType::Sea, 0));
        
    }

    // Method to get tile information, place settlements/roads, etc.
};
