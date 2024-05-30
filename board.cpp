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
        vector<Structure*> structures; 

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
