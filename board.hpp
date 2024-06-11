/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "Tile.cpp"

using namespace std;

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

            // -----------------------------line 1-----------------------------
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
                currentTile->neighbors.push_back(tiles[12]); // Hills, 10
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
            }

            // -----------------------------line 2-----------------------------
            if (i == 9) { // Fields, 12
                currentTile->neighbors.push_back(tiles[8]); // sea
                currentTile->neighbors.push_back(tiles[8]); // sea
                currentTile->neighbors.push_back(tiles[4]); // Mountains, 10
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
                currentTile->neighbors.push_back(tiles[15]); // Fields, 9
            }
            if (i == 10) { // Hills, 6
                currentTile->neighbors.push_back(tiles[9]); // Fields, 12
                currentTile->neighbors.push_back(tiles[4]); // Mountains, 10
                currentTile->neighbors.push_back(tiles[5]); // Pasture, 2
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
            }
            if (i == 11) { // Pasture, 4
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
                currentTile->neighbors.push_back(tiles[5]); // Pasture, 2
                currentTile->neighbors.push_back(tiles[6]); // Forest, 9
                currentTile->neighbors.push_back(tiles[12]); // Hills, 10
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
            }
            if (i == 12) { // Hills, 10
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
                currentTile->neighbors.push_back(tiles[6]); // Forest, 9
                currentTile->neighbors.push_back(tiles[13]); // sea
                currentTile->neighbors.push_back(tiles[13]); // sea
                currentTile->neighbors.push_back(tiles[19]); // Mountains, 8
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3
            }

            // -----------------------------line 3-----------------------------
            if (i == 15) { // Fields, 9
                currentTile->neighbors.push_back(tiles[14]); // sea
                currentTile->neighbors.push_back(tiles[14]); // sea
                currentTile->neighbors.push_back(tiles[9]); // Fields, 12
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
                currentTile->neighbors.push_back(tiles[22]); // Forest, 8
                currentTile->neighbors.push_back(tiles[14]); // sea
            }
            if (i == 16) { // Forest, 11
                currentTile->neighbors.push_back(tiles[15]); // Fields, 9
                currentTile->neighbors.push_back(tiles[9]); // Fields, 12
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
                currentTile->neighbors.push_back(tiles[22]); // Forest, 8
            }
            if (i == 17) { // Desert, -1
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
                currentTile->neighbors.push_back(tiles[10]); // Hills, 6
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
            }
            if (i == 18) { // Forest, 3
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
                currentTile->neighbors.push_back(tiles[11]); // Pasture, 4
                currentTile->neighbors.push_back(tiles[12]); // Hills, 10
                currentTile->neighbors.push_back(tiles[19]); // Mountains, 8
                currentTile->neighbors.push_back(tiles[25]); // Pasture, 5
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
            }
            if (i == 19) { // Mountains, 8
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3
                currentTile->neighbors.push_back(tiles[12]); // Hills, 10
                currentTile->neighbors.push_back(tiles[20]); // sea
                currentTile->neighbors.push_back(tiles[20]); // sea
                currentTile->neighbors.push_back(tiles[20]); // sea
                currentTile->neighbors.push_back(tiles[25]); // Pasture, 5
            }

            // -----------------------------line 4-----------------------------
            if (i == 22) { // Forest, 8
                currentTile->neighbors.push_back(tiles[21]); // sea
                currentTile->neighbors.push_back(tiles[15]); // Fields, 9
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
                currentTile->neighbors.push_back(tiles[28]); // Hills, 5
                currentTile->neighbors.push_back(tiles[21]); // sea
            }
            if (i == 23) { // Mountains, 3
                currentTile->neighbors.push_back(tiles[22]); // Forest, 8
                currentTile->neighbors.push_back(tiles[16]); // Forest, 11
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
                currentTile->neighbors.push_back(tiles[29]); // Fields, 6
                currentTile->neighbors.push_back(tiles[28]); // Hills, 5
            }
            if (i == 24) { // Fields, 4
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
                currentTile->neighbors.push_back(tiles[17]); // Desert, -1
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3 
                currentTile->neighbors.push_back(tiles[25]); // Pasture, 5
                currentTile->neighbors.push_back(tiles[30]); // Pasture, 11
                currentTile->neighbors.push_back(tiles[29]); // Fields, 6
            }
            if (i == 25) { // Pasture, 5
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
                currentTile->neighbors.push_back(tiles[18]); // Forest, 3 
                currentTile->neighbors.push_back(tiles[19]); // Mountains, 8
                currentTile->neighbors.push_back(tiles[26]); // sea
                currentTile->neighbors.push_back(tiles[26]); // sea
                currentTile->neighbors.push_back(tiles[30]); // Pasture, 11
            }

            // -----------------------------line 5-----------------------------
            if (i == 28) { // Hills, 5
                currentTile->neighbors.push_back(tiles[27]); // sea
                currentTile->neighbors.push_back(tiles[22]); // Forest, 8
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
                currentTile->neighbors.push_back(tiles[29]); // Fields, 6
                currentTile->neighbors.push_back(tiles[32]); // sea
                currentTile->neighbors.push_back(tiles[32]); // sea
            }
            if (i == 29) { // Fields, 6
                currentTile->neighbors.push_back(tiles[28]); // Hills, 5
                currentTile->neighbors.push_back(tiles[23]); // Mountains, 3
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
                currentTile->neighbors.push_back(tiles[30]); // Pasture, 11
                currentTile->neighbors.push_back(tiles[33]); // sea
                currentTile->neighbors.push_back(tiles[33]); // sea
            }
            if (i == 30) { // Pasture, 11
                currentTile->neighbors.push_back(tiles[29]); // Fields, 6 
                currentTile->neighbors.push_back(tiles[24]); // Fields, 4
                currentTile->neighbors.push_back(tiles[25]); // Pasture, 5
                currentTile->neighbors.push_back(tiles[31]); // sea
                currentTile->neighbors.push_back(tiles[34]); // sea
                currentTile->neighbors.push_back(tiles[34]); // sea
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



#endif // BOARD_HPP
