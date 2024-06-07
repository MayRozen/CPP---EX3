/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "Tile.cpp"
#include "Structure.cpp"
#include "player.hpp"
using namespace std;

namespace ariel{

// -----------------------------Structure-----------------------------
    void Player::addRoad() {  // Requires: Brick & Lumber
        int BrickSum = 0, LumberSum = 0;
        int indexBrick = 0, indexLumber = 0;
        vector<ReturnRes> r = this->returnRes;

        for(size_t i=0; i<r.size(); i++){
            if(r[i]==ReturnRes::Brick){
                BrickSum++;
                indexBrick = i;
            }
            if(r[i]==ReturnRes::Lumber){
                LumberSum++;
                indexLumber = i;
            }
        }

        if(BrickSum>=1 && LumberSum>=1){
            this->settlements.push_back(road()); // We can add a road due to it is heir from settlements
            int checkB = 0, checkL = 0;
            for(size_t i=0; i<r.size(); i++){
                if(checkB!=1 && r[i]==ReturnRes::Brick){
                    this->returnRes.erase(r.begin()+i);
                    checkB = 1;
                }
                if(checkL!=1 && r[i]==ReturnRes::Lumber){
                    this->returnRes.erase(r.begin()+i);
                    checkL = 1;
                }
                if(checkB==1 && checkL==1){
                    cout<<"A New rode has been successfully added to: "<< this->name<<endl;
                    return;
                }
            }
        }

        cout<<"The rode can not be added to: "<< this->name<<endl; 
    }

    void Player::addSettlement() { // Requires: Brick, Lumber, Wool, & Grain
        int BrickSum = 0, LumberSum = 0, WoolSum = 0, GrainSum = 0;
        int indexBrick = 0, indexLumber = 0, indexWool = 0, indexGrain = 0;
        vector<ReturnRes> r = this->returnRes;

        for(size_t i=0; i<r.size(); i++){
            if(r[i]==ReturnRes::Brick){
                BrickSum++;
                indexBrick = i;
            }
            if(r[i]==ReturnRes::Lumber){
                LumberSum++;
                indexLumber = i;
            }
            if(r[i]==ReturnRes::Wool){
                WoolSum++;
                indexWool = i;
            }
            if(r[i]==ReturnRes::Grain){
                GrainSum++;
                indexGrain = i;
            }
        }

        if(BrickSum>=1 && LumberSum>=1 && WoolSum>=1 && GrainSum>=1 ){
            this->settlements.push_back(settlement()); // We can add a settlement due to it is heir from settlements
            int checkB = 0, checkL = 0, checkW = 0, checkG = 0;
            for(size_t i=0; i<r.size(); i++){
                if(r[i]==ReturnRes::Brick){
                    this->returnRes.erase(r.begin()+i);
                    checkB = 1;
                }
                if(r[i]==ReturnRes::Lumber){
                    this->returnRes.erase(r.begin()+i);
                    checkL = 1;
                }
                if(r[i]==ReturnRes::Wool){
                    this->returnRes.erase(r.begin()+i);
                    checkW = 1;
                }
                if(r[i]==ReturnRes::Grain){
                    this->returnRes.erase(r.begin()+i);
                    checkG = 1;
                }
            if(checkB==1 && checkL==1 && checkW==1 && checkG ==1){
                    cout<<"A New Settlement has been successfully added to: "<< this->name<<endl;
                    this->sumPoints=this->sumPoints++;
                    return;
                }
            }
        }

        cout<<"The Settlement can not be added to: "<< this->name<<endl;  
    }

    void Player::addCity() { // Requires: 3 Ore & 2 Grain
        int OreSum = 0, GrainSum = 0;
        int indexOre = 0, indexGrain = 0;
        vector<ReturnRes> r = this->returnRes;

        for(size_t i=0; i<r.size(); i++){
            if(r[i]==ReturnRes::Brick){
                OreSum++;
                indexOre = i;
            }
            if(r[i]==ReturnRes::Lumber){
                GrainSum++;
                indexGrain = i;
            }
        }

        if(OreSum>=3 && GrainSum>=2){
            this->settlements.push_back(city()); // We can add a city due to it is heir from settlements
            int checkO = 0, checkG = 0;
            for(size_t i=0; i<r.size(); i++){
                if(r[i]==ReturnRes::Brick){
                    this->returnRes.erase(r.begin()+i);
                    checkO++;
                }
                if(r[i]==ReturnRes::Lumber){
                    this->returnRes.erase(r.begin()+i);
                    checkG++;
                }
            if(checkO==3 && checkG==2){
                    cout<<"A New city has been successfully added to: "<< this->name<<endl;
                    this->sumPoints=this->sumPoints++;
                    return;
                }
            }
        }

        cout<<"The city can not be added to: "<< this->name<<endl;  
    }

    void Player::printPlayerInfo() {
        cout << "Roads:" << endl;
        for (const auto& road : roads) {
            cout << "Name: " << road.name << endl;
        }

        cout << "Settlements:" << endl;
        for (const auto& settlement : settlements) {
            cout << "Name: " << settlement.name << endl;
        }

        cout << "Cities:" << endl;
        for (const auto& city : cities) {
            cout << "Name: " << city.name << endl;
        }
    }

    // void placeSettelemnt(places, placesNum, board);

    void Player::placeRoad(Tile* tile1, Tile* tile2){
        addRoad(); // Checking the required resources and add a new road
        Structure* newRoad = &(this->roads.back()); // Get a pointer to the new road

        // Checking the index of the new road in tile1 and tile2
        size_t indexTile1 = -1, indexTile2 = -1;
        for(size_t i=0; i<6; i++){
            if(tile1->neighbors[i]==tile2){
                indexTile1 = i;
            }
            if(tile2->neighbors[i]==tile1){
                indexTile2 = i;
            }
        }

        if (indexTile1!=-1 && indexTile2!=-1) {
            tile1->edges.insert(tile1->edges.begin() + indexTile1, newRoad); // The newRoad will be at indexTile1
            tile2->edges.insert(tile1->edges.begin() + indexTile2, newRoad);
        } else {
            cerr << "Error: The tiles do not share an edge." << endl;
        }
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum) { // p1 continues to build a road.
        string st1=places[0], st2=places[1];
        int num1=placesNum[0], num2=placesNum[1];
        ResourceType R1, R2;
        // ResourceType { Hills, Forest, Mountains, Fields, Pasture, Desert, Sea };
        if(st1=="Hills"){
            R1 = ResourceType::Hills;
        } else if(st1=="Forest"){
            R1 = ResourceType::Forest;
        } else if(st1=="Mountains"){
            R1 = ResourceType::Mountains;
        } else if(st1=="Fields"){
            R1 = ResourceType::Fields;
        } else if(st1=="Pasture"){
            R1 = ResourceType::Pasture;
        } else if(st1=="Desert"){
            R1 = ResourceType::Desert;
        } else if(st1=="Sea"){
            R1 = ResourceType::Sea;
        }

        if(st2=="Hills"){
            R2 = ResourceType::Hills;
        } else if(st2=="Forest"){
            R2 = ResourceType::Forest;
        } else if(st2=="Mountains"){
            R2 = ResourceType::Mountains;
        } else if(st2=="Fields"){
            R2 = ResourceType::Fields;
        } else if(st2=="Pasture"){
            R2 = ResourceType::Pasture;
        } else if(st2=="Desert"){
            R2 = ResourceType::Desert;
        } else if(st2=="Sea"){
            R2 = ResourceType::Sea;
        }


        Tile* tile1 = new Tile(R1, num1);
        Tile* tile2 = new Tile(R2, num2);

        placeRoad(tile1, tile2);
    }

    // Check for two consecutive roads
    bool Player::canPlaceSettlement(Tile* tile1, Tile* tile2, Tile* tile3) {
        size_t indexTile2=0, indexTile3=0; // tile1
        size_t indexTile12=0, indexTile32=0; // tile2
        size_t indexTile23=0, indexTile13=0; // tile3
        for (size_t i=0; i<6; i++) {
            Tile* t = tile1->neighbors[i]; // Pointer to the i'th neighbor

            // tile1
            if(tile1->neighbors[i]==tile2){ // if it is tile2
                indexTile2 = i; // save the index of it --in tile1 ! --
            }
            if(tile1->neighbors[i]==tile3){ // if it is tile3
                indexTile3 = i;
            }

            // tile2
            if(tile2->neighbors[i]==tile1){ // if it is tile1
                indexTile12 = i;
            }
            if(tile2->neighbors[i]==tile3){ // if it is tile3
                indexTile32 = i;
            }

            // tile3
            if(tile3->neighbors[i]==tile2){ // if it is tile2
                indexTile23 = i;
            }
            if(tile3->neighbors[i]==tile1){ // if it is tile1
                indexTile13 = i;
            }
        }

        // Ensure tiles are nearby
        if (indexTile2 == -1 || indexTile3 == -1) {
            return false; // One or both tiles are not neighbors of tile1
        }

        size_t smaller=0, bigger=0;

        // tile1
        if(indexTile2>indexTile3){
            smaller = indexTile3;
            bigger = indexTile2;
        } else{
            smaller = indexTile2;
            bigger = indexTile3;
        }

        if(((tile1->edges[smaller] != NULL) && (tile1->edges[smaller-1] != NULL)) ||
            ((tile1->edges[bigger] != NULL) && (tile1->edges[bigger+1] != NULL))){
                return true;
            }

        // tile2
        if(indexTile12>indexTile32){
            smaller = indexTile32;
            bigger = indexTile12;
        } else{
            smaller = indexTile12;
            bigger = indexTile32;
        }
        
        if(((tile2->edges[smaller] != NULL) && (tile2->edges[smaller-1] != NULL)) ||
            ((tile2->edges[bigger] != NULL) && (tile2->edges[bigger+1] != NULL))){
                return true;
            }

        // tile3
        if(indexTile23>indexTile13){
            smaller = indexTile13;
            bigger = indexTile23;
        } else{
            smaller = indexTile23;
            bigger = indexTile13;
        }

        if(((tile3->edges[smaller] != NULL) && (tile3->edges[smaller-1] != NULL)) ||
            ((tile3->edges[bigger] != NULL) && (tile3->edges[bigger+1] != NULL))){
                return true;
            }
        
        return false;
    }

    void Player::placeSettelemnt(vector<string> places, vector<int> placesNum){
        string st1=places[0], st2=places[1], st3=places[2];
        int num1=placesNum[0], num2=placesNum[1], num3=placesNum[2];
        ResourceType R1, R2, R3;
        // ResourceType { Hills, Forest, Mountains, Fields, Pasture, Desert, Sea };
        if(st1=="Hills"){
            R1 = ResourceType::Hills;
        } else if(st1=="Forest"){
            R1 = ResourceType::Forest;
        } else if(st1=="Mountains"){
            R1 = ResourceType::Mountains;
        } else if(st1=="Fields"){
            R1 = ResourceType::Fields;
        } else if(st1=="Pasture"){
            R1 = ResourceType::Pasture;
        } else if(st1=="Desert"){
            R1 = ResourceType::Desert;
        } else if(st1=="Sea"){
            R1 = ResourceType::Sea;
        }

        if(st2=="Hills"){
            R2 = ResourceType::Hills;
        } else if(st2=="Forest"){
            R2 = ResourceType::Forest;
        } else if(st2=="Mountains"){
            R2 = ResourceType::Mountains;
        } else if(st2=="Fields"){
            R2 = ResourceType::Fields;
        } else if(st2=="Pasture"){
            R2 = ResourceType::Pasture;
        } else if(st2=="Desert"){
            R2 = ResourceType::Desert;
        } else if(st2=="Sea"){
            R2 = ResourceType::Sea;
        }

        if(st3=="Hills"){
            R3 = ResourceType::Hills;
        } else if(st3=="Forest"){
            R3 = ResourceType::Forest;
        } else if(st3=="Mountains"){
            R3 = ResourceType::Mountains;
        } else if(st3=="Fields"){
            R3 = ResourceType::Fields;
        } else if(st3=="Pasture"){
            R3 = ResourceType::Pasture;
        } else if(st3=="Desert"){
            R3 = ResourceType::Desert;
        } else if(st3=="Sea"){
            R3 = ResourceType::Sea;
        }


        Tile* tile1 = new Tile(R1, num1);
        Tile* tile2 = new Tile(R2, num2);
        Tile* tile3 = new Tile(R3, num3);

        placeSettlements(tile1, tile2, tile3);
    }

    void Player::placeSettlements(Tile* tile1, Tile* tile2, Tile* tile3){
        if(!canPlaceSettlement(tile1, tile2, tile3)){ // The three tiles are not nearby
            return;
        }

        addSettlement(); // Checking the required resources and add a new settlement
        Structure* newSettlement = &(this->settlements.back()); // Get a pointer to the new settlement

        // Checking the index of the new settlement in tile1, tile2 and tile3
        size_t indexTile1 = -1, indexTile2 = -1, indexTile3 = -1;
        for(size_t i=0; i<6; i++){
            if(tile1->neighbors[i]==tile2 && tile1->neighbors[i]==tile3){ // tile1
                indexTile1 = i;
            }
            if(tile2->neighbors[i]==tile1 && tile2->neighbors[i]==tile3){ // tile2
                indexTile2 = i;
            }
            if(tile3->neighbors[i]==tile1 && tile3->neighbors[i]==tile2){ // tile3
                indexTile3 = i;
            }
        }

        if (indexTile1!=-1 && indexTile2!=-1 && indexTile3!=-1) {
            tile1->vertices.insert(tile1->vertices.begin() + indexTile1, newSettlement); // The newSettlement will be at indexTile1
            tile2->vertices.insert(tile1->vertices.begin() + indexTile2, newSettlement);
            tile3->vertices.insert(tile1->vertices.begin() + indexTile3, newSettlement);
        } else {
            cerr << "Error: The tiles do not share an vertex." << endl;
        }
    }

    void Player::placeCity(Tile* tile1, Tile* tile2, Tile* tile3){
        addCity(); // Checking the required resources and add a new City
        Structure* newCity = &(this->cities.back()); // Get a pointer to the new City

        // Checking the index of the new City in tile1, tile2 and tile3
        size_t indexTile1 = -1, indexTile2 = -1, indexTile3 = -1;
        for(size_t i=0; i<6; i++){
            if(tile1->neighbors[i]==tile2 && tile1->neighbors[i]==tile3){ // tile1
                indexTile1 = i;
            }
            if(tile2->neighbors[i]==tile1 && tile2->neighbors[i]==tile3){ // tile2
                indexTile2 = i;
            }
            if(tile3->neighbors[i]==tile1 && tile3->neighbors[i]==tile2){ // tile3
                indexTile3 = i;
            }
        }

        if (indexTile1!=-1 && indexTile2!=-1 && indexTile3!=-1) {

            // There is a settlement
            if((tile1->vertices[indexTile1] != nullptr)&&
                (tile2->vertices[indexTile2] != nullptr)&&
                (tile3->vertices[indexTile2] != nullptr)) {

                tile1->vertices.insert(tile1->vertices.begin() + indexTile1, newCity); // The newCity will be at indexTile1
                tile2->vertices.insert(tile1->vertices.begin() + indexTile2, newCity);
                tile3->vertices.insert(tile1->vertices.begin() + indexTile3, newCity);
            }
        } else {
            cerr << "Error: The tiles do not share an vertex." << endl;
        }
    }

// -----------------------------Game Logic-----------------------------
    void rollDice() {
        // Seed the random number generator with current time
        srand(time(nullptr));

        // Generate two random numbers between 1 and 6 (inclusive) for two dice
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        // Output the results
        cout << "Dice 1: " << dice1 << endl;
        cout << "Dice 2: " << dice2 << endl;
        cout << "Total: " << dice1 + dice2 << endl;
    }
}
