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
            for (size_t i = 0; i < 34; ++i) {
                
                // Define neighbors based on the relative positions in the board

                // Sea -> continue

                // -----------------------------line 1-----------------------------
                if (i == 4) { // Mountains, 10
                    tiles[i]->neighbors[0] = getTileAt(3); // sea
                    tiles[i]->neighbors[1] = getTileAt(0); // sea
                    tiles[i]->neighbors[2] = getTileAt(0); // sea
                    tiles[i]->neighbors[3] = getTileAt(5); // Pasture, 2
                    tiles[i]->neighbors[4] = getTileAt(10); // Hills, 6
                    tiles[i]->neighbors[5] = getTileAt(9); // Fields, 12
                }
                if (i == 5) { // Pasture, 2
                    tiles[i]->neighbors[0] = getTileAt(4); // Mountains, 10
                    tiles[i]->neighbors[1] = getTileAt(1); // sea
                    tiles[i]->neighbors[2] = getTileAt(1); // sea
                    tiles[i]->neighbors[3] = getTileAt(6); // Forest, 9
                    tiles[i]->neighbors[4] = getTileAt(11); // Pasture, 4
                    tiles[i]->neighbors[5] = getTileAt(10); // Hills, 6
                }
                if (i == 6) { // Forest, 9
                    tiles[i]->neighbors[0] = getTileAt(5); // Pasture, 2
                    tiles[i]->neighbors[1] = getTileAt(2); // sea
                    tiles[i]->neighbors[2] = getTileAt(2); // sea
                    tiles[i]->neighbors[3] = getTileAt(7); // sea
                    tiles[i]->neighbors[4] = getTileAt(12); // Hills, 10
                    tiles[i]->neighbors[5] = getTileAt(11); // Pasture, 4
                }

                // -----------------------------line 2-----------------------------
                if (i == 9) { // Fields, 12
                    tiles[i]->neighbors[0] = getTileAt(8); // sea
                    tiles[i]->neighbors[1] = getTileAt(8); // sea
                    tiles[i]->neighbors[2] = getTileAt(4); // Mountains, 10
                    tiles[i]->neighbors[3] = getTileAt(10); // Hills, 6
                    tiles[i]->neighbors[4] = getTileAt(16); // Forest, 11
                    tiles[i]->neighbors[5] = getTileAt(15); // Fields, 9
                }
                if (i == 10) { // Hills, 6
                    tiles[i]->neighbors[0] = getTileAt(9); // Fields, 12
                    tiles[i]->neighbors[1] = getTileAt(4); // Mountains, 10
                    tiles[i]->neighbors[2] = getTileAt(5); // Pasture, 2
                    tiles[i]->neighbors[3] = getTileAt(11); // Pasture, 4
                    tiles[i]->neighbors[4] = getTileAt(17); // Desert, -1
                    tiles[i]->neighbors[5] = getTileAt(16); // Forest, 11
                }
                if (i == 11) { // Pasture, 4
                    tiles[i]->neighbors[0] = getTileAt(10); // Hills, 6
                    tiles[i]->neighbors[1] = getTileAt(5); // Pasture, 2
                    tiles[i]->neighbors[2] = getTileAt(6); // Forest, 9
                    tiles[i]->neighbors[3] = getTileAt(12); // Hills, 10
                    tiles[i]->neighbors[4] = getTileAt(18); // Forest, 3
                    tiles[i]->neighbors[5] = getTileAt(17); // Desert, -1
                }
                if (i == 12) { // Hills, 10
                    tiles[i]->neighbors[0] = getTileAt(11); // Pasture, 4
                    tiles[i]->neighbors[1] = getTileAt(6); // Forest, 9
                    tiles[i]->neighbors[2] = getTileAt(13); // sea
                    tiles[i]->neighbors[3] = getTileAt(13); // sea
                    tiles[i]->neighbors[4] = getTileAt(19); // Mountains, 8
                    tiles[i]->neighbors[5] = getTileAt(18); // Forest, 3
                }

                // -----------------------------line 3-----------------------------
                if (i == 15) { // Fields, 9
                    tiles[i]->neighbors[0] = getTileAt(14); // sea
                    tiles[i]->neighbors[1] = getTileAt(14); // sea
                    tiles[i]->neighbors[2] = getTileAt(9); // Fields, 12
                    tiles[i]->neighbors[3] = getTileAt(16); // Forest, 11
                    tiles[i]->neighbors[4] = getTileAt(22); // Forest, 8
                    tiles[i]->neighbors[5] = getTileAt(14); // sea
                }
                if (i == 16) { // Forest, 11
                    tiles[i]->neighbors[0] = getTileAt(15); // Fields, 9
                    tiles[i]->neighbors[1] = getTileAt(9); // Fields, 12
                    tiles[i]->neighbors[2] = getTileAt(10); // Hills, 6
                    tiles[i]->neighbors[3] = getTileAt(17); // Desert, -1
                    tiles[i]->neighbors[4] = getTileAt(23); // Mountains, 3
                    tiles[i]->neighbors[5] = getTileAt(22); // Forest, 8
                }
                if (i == 17) { // Desert, -1
                    tiles[i]->neighbors[0] = getTileAt(16); // Forest, 11
                    tiles[i]->neighbors[1] = getTileAt(10); // Hills, 6
                    tiles[i]->neighbors[2] = getTileAt(11); // Pasture, 4
                    tiles[i]->neighbors[3] = getTileAt(18); // Forest, 3
                    tiles[i]->neighbors[4] = getTileAt(24); // Fields, 4
                    tiles[i]->neighbors[5] = getTileAt(23); // Mountains, 3
                }
                if (i == 18) { // Forest, 3
                    tiles[i]->neighbors[0] = getTileAt(17); // Desert, -1
                    tiles[i]->neighbors[1] = getTileAt(11); // Pasture, 4
                    tiles[i]->neighbors[2] = getTileAt(12); // Hills, 10
                    tiles[i]->neighbors[3] = getTileAt(19); // Mountains, 8
                    tiles[i]->neighbors[4] = getTileAt(25); // Pasture, 5
                    tiles[i]->neighbors[5] = getTileAt(24); // Fields, 4
                }
                if (i == 19) { // Mountains, 8
                    tiles[i]->neighbors[0] = getTileAt(18); // Forest, 3
                    tiles[i]->neighbors[1] = getTileAt(12); // Hills, 10
                    tiles[i]->neighbors[2] = getTileAt(20); // sea
                    tiles[i]->neighbors[3] = getTileAt(20); // sea
                    tiles[i]->neighbors[4] = getTileAt(20); // sea
                    tiles[i]->neighbors[5] = getTileAt(25); // Pasture, 5
                }

                // -----------------------------line 4-----------------------------
                if (i == 22) { // Forest, 8
                    tiles[i]->neighbors[0] = getTileAt(21); // sea
                    tiles[i]->neighbors[1] = getTileAt(15); // Fields, 9
                    tiles[i]->neighbors[2] = getTileAt(16); // Forest, 11
                    tiles[i]->neighbors[3] = getTileAt(23); // Mountains, 3
                    tiles[i]->neighbors[4] = getTileAt(28); // Hills, 5
                    tiles[i]->neighbors[5] = getTileAt(21); // sea
                }
                if (i == 23) { // Mountains, 3
                    tiles[i]->neighbors[0] = getTileAt(22); // Forest, 8
                    tiles[i]->neighbors[1] = getTileAt(16); // Forest, 11
                    tiles[i]->neighbors[2] = getTileAt(17); // Desert, -1
                    tiles[i]->neighbors[3] = getTileAt(24); // Fields, 4
                    tiles[i]->neighbors[4] = getTileAt(29); // Fields, 6
                    tiles[i]->neighbors[5] = getTileAt(28); // Hills, 5
                }
                if (i == 24) { // Fields, 4
                    tiles[i]->neighbors[0] = getTileAt(23); // Mountains, 3
                    tiles[i]->neighbors[1] = getTileAt(17); // Desert, -1
                    tiles[i]->neighbors[2] = getTileAt(18); // Forest, 3 
                    tiles[i]->neighbors[3] = getTileAt(25); // Pasture, 5
                    tiles[i]->neighbors[4] = getTileAt(30); // Pasture, 11
                    tiles[i]->neighbors[5] = getTileAt(29); // Fields, 6
                }
                if (i == 25) { // Pasture, 5
                    tiles[i]->neighbors[0] = getTileAt(24); // Fields, 4
                    tiles[i]->neighbors[1] = getTileAt(18); // Forest, 3 
                    tiles[i]->neighbors[2] = getTileAt(19); // Mountains, 8
                    tiles[i]->neighbors[3] = getTileAt(26); // sea
                    tiles[i]->neighbors[4] = getTileAt(26); // sea
                    tiles[i]->neighbors[5] = getTileAt(30); // Pasture, 11
                }

                // -----------------------------line 5-----------------------------
                if (i == 28) { // Hills, 5
                    tiles[i]->neighbors[0] = getTileAt(27); // sea
                    tiles[i]->neighbors[1] = getTileAt(22); // Forest, 8
                    tiles[i]->neighbors[2] = getTileAt(23); // Mountains, 3
                    tiles[i]->neighbors[3] = getTileAt(29); // Fields, 6
                    tiles[i]->neighbors[4] = getTileAt(32); // sea
                    tiles[i]->neighbors[5] = getTileAt(32); // sea
                }
                if (i == 29) { // Fields, 6
                    tiles[i]->neighbors[0] = getTileAt(28); // Hills, 5
                    tiles[i]->neighbors[1] = getTileAt(23); // Mountains, 3
                    tiles[i]->neighbors[2] = getTileAt(24); // Fields, 4
                    tiles[i]->neighbors[3] = getTileAt(30); // Pasture, 11
                    tiles[i]->neighbors[4] = getTileAt(33); // sea
                    tiles[i]->neighbors[5] = getTileAt(33); // sea
                }
                if (i == 30) { // Pasture, 11
                    tiles[i]->neighbors[0] = getTileAt(29); // Fields, 6 
                    tiles[i]->neighbors[1] = getTileAt(24); // Fields, 4
                    tiles[i]->neighbors[2] = getTileAt(25); // Pasture, 5
                    tiles[i]->neighbors[3] = getTileAt(31); // sea
                    tiles[i]->neighbors[4] = getTileAt(34); // sea
                    tiles[i]->neighbors[5] = getTileAt(34); // sea
                }
            }         
        }

        Board() {
            initialize();
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
    };



#endif // BOARD_HPP
