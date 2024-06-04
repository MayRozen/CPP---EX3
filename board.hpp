/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "Tile.cpp"
#include "Structure.cpp"

using namespace std;

namespace ariel{
    class Board {
    private:
        // Vector to store pointers to tiles
        vector<Tile*> tiles; 

        /* Number of tiles in the widest row:
              0  1  2             // sea
             3 4 5 6 7            // line 1
          8 9 10 11 12 13         // line 2
        14 15 16 17 18 19 20      // line 3
          21 22 23 24 25 26       // line 4
            27 28 29 30 31        // line 5
              32 33 34            // sea
        */
        int boardIndex; 

    public:
        Board() {
            initialize();
        }

        void initialize() {
            // The board is arranged according to the example which in the rules book - from the left to the right.

            // -----------------------------Sea-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));
            tiles.push_back(new Tile(ResourceType::Sea, 0));
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------line 1-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            tiles.push_back(new Tile(ResourceType::Mountains, 10));
            tiles.push_back(new Tile(ResourceType::Pasture, 2));
            tiles.push_back(new Tile(ResourceType::Forest, 9));

            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------line 2-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            tiles.push_back(new Tile(ResourceType::Fields, 12));
            tiles.push_back(new Tile(ResourceType::Hills, 6));
            tiles.push_back(new Tile(ResourceType::Pasture, 4));
            tiles.push_back(new Tile(ResourceType::Hills, 10));

            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------line 3-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            tiles.push_back(new Tile(ResourceType::Fields, 9));
            tiles.push_back(new Tile(ResourceType::Forest, 11));
            tiles.push_back(new Tile(ResourceType::Desert, -1));
            tiles.push_back(new Tile(ResourceType::Forest, 3));
            tiles.push_back(new Tile(ResourceType::Mountains, 8));

            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------line 4-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            tiles.push_back(new Tile(ResourceType::Forest, 8));
            tiles.push_back(new Tile(ResourceType::Mountains, 3));
            tiles.push_back(new Tile(ResourceType::Fields, 4));
            tiles.push_back(new Tile(ResourceType::Pasture, 5));

            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------line 5-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));

            tiles.push_back(new Tile(ResourceType::Hills, 5));
            tiles.push_back(new Tile(ResourceType::Fields, 6));
            tiles.push_back(new Tile(ResourceType::Pasture, 11));

            tiles.push_back(new Tile(ResourceType::Sea, 0));

            // -----------------------------Sea-----------------------------
            tiles.push_back(new Tile(ResourceType::Sea, 0));
            tiles.push_back(new Tile(ResourceType::Sea, 0));
            tiles.push_back(new Tile(ResourceType::Sea, 0));


        // Define neighbors for each tile
        for (size_t i = 0; i < tiles.size(); ++i) {
            Tile* currentTile = tiles[i];
            
            // Define neighbors based on the relative positions in the board

            // Sea -> continue
            if (i < 4 || i==7 || // sea + line1
                i==8 || i==13 || // line 2
                i==14 || i==20 || // line 3
                i==21 || i==26 || // line 4
                i==27 || i<=31) { // line 5 + sea
                continue;
            }
            if (i == 4) { // Mountains, 10
                currentTile->neighbors.push_back(tiles[3]); // sea
                currentTile->neighbors.push_back(tiles[0]); // sea
                currentTile->neighbors.push_back(tiles[0]); // sea
                currentTile->neighbors.push_back(tiles[5]); // Pasture, 2
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
                currentTile->neighbors.push_back(tiles[9]); // Fields, 12
            }
            if (i == 5) { // Pasture, 2
                currentTile->neighbors.push_back(tiles[4]); // Mountains, 10
                currentTile->neighbors.push_back(tiles[1]); // sea
                currentTile->neighbors.push_back(tiles[1]); // sea
                currentTile->neighbors.push_back(tiles[6]); // Forest, 9
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
            }
            if (i == 6) { // Forest, 9
                currentTile->neighbors.push_back(tiles[5]); // Pasture, 2
                currentTile->neighbors.push_back(tiles[2]); // sea
                currentTile->neighbors.push_back(tiles[2]); // sea
                currentTile->neighbors.push_back(tiles[7]); // sea
                currentTile->neighbors.push_back(tiles[12]); //Hills, 10
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
            }
            if (i == 4) {
                currentTile->neighbors.push_back(tiles[i - 1]); // Left neighbor
            }
            if (i == 4) { 
                currentTile->neighbors.push_back(tiles[i + 1]); // Right neighbor
            }
        }
            
        }

        ~Board(){ // Destructor - clean all the board
            for (Tile* tile : tiles) { // Free memory allocated for tiles
                delete tile;
            }
            boardIndex = 0;
        }

        vector<Tile*> getTiles() const;
        int getBoardIndex() const;
        void printAsMatrix() const; // Print the board as a matrix
        Tile* getTileAt(int boardIndex) const; // Method to get tile at specified position

        // Add methods for placing settlements, roads, etc.
    };

} 

#endif // BOARD_HPP
