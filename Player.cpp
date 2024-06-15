/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <memory>
#include "player.hpp"
#include "catan.hpp"
using namespace std;

    size_t findIndex(vector<DevelopmentCard*>& arr, CardType D){
        for(size_t i=0; i<arr.size(); i++){
            if(arr[i]->getCardName() == arr[i]->toString(D)){
                return i;
            }
        }
        return (size_t)-1;
    }

    string Player::Resto_string(ReturnRes res) {
        switch (res) {
            case ReturnRes::Lumber: return "Lumber";
            case ReturnRes::Brick: return "Brick";
            case ReturnRes::Wool: return "Wool";
            case ReturnRes::Grain: return "Grain";
            case ReturnRes::Ore: return "Ore";
            default: return "Unknown";
        }
    }

    ReturnRes Player::fromStringToRes(string st1){
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

// -----------------------------Structure-----------------------------
    void Player::addRoad() {  // Requires: Brick & Lumber
        int BrickSum = 0, LumberSum = 0;
        int indexBrick = 0, indexLumber = 0;

        for(size_t i=0; i<this->returnRes.size(); i++){
            if(this->returnRes[i]==ReturnRes::Brick){
                BrickSum++;
                indexBrick = i;
            }
            if(this->returnRes[i]==ReturnRes::Lumber){
                LumberSum++;
                indexLumber = i;
            }
        }

        if(BrickSum>=1 && LumberSum>=1){ // We can build a new road
            this->settlements.push_back(road()); // We can add a road due to it is heir from settlements
            int checkB = 0, checkL = 0;
            for(size_t i=0; i<this->returnRes.size(); i++){
                if(checkB!=1 && this->returnRes[i]==ReturnRes::Brick){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkB = 1;
                }
                if(checkL!=1 && this->returnRes[i]==ReturnRes::Lumber){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
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

        for(size_t i=0; i<this->returnRes.size(); i++){
            if(this->returnRes[i]==ReturnRes::Brick){
                BrickSum++;
                indexBrick = i;
            }
            if(this->returnRes[i]==ReturnRes::Lumber){
                LumberSum++;
                indexLumber = i;
            }
            if(this->returnRes[i]==ReturnRes::Wool){
                WoolSum++;
                indexWool = i;
            }
            if(this->returnRes[i]==ReturnRes::Grain){
                GrainSum++;
                indexGrain = i;
            }
        }

        if(BrickSum>=1 && LumberSum>=1 && WoolSum>=1 && GrainSum>=1 ){
            this->settlements.push_back(settlement()); // We can add a settlement due to it is heir from settlements
            int checkB = 0, checkL = 0, checkW = 0, checkG = 0;
            for(size_t i=0; i<this->returnRes.size(); i++){
                if(this->returnRes[i]==ReturnRes::Brick){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkB = 1;
                }
                if(this->returnRes[i]==ReturnRes::Lumber){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkL = 1;
                }
                if(this->returnRes[i]==ReturnRes::Wool){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkW = 1;
                }
                if(this->returnRes[i]==ReturnRes::Grain){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkG = 1;
                }
            if(checkB==1 && checkL==1 && checkW==1 && checkG ==1){
                    cout<<"A New Settlement has been successfully added to: "<< this->name<<endl;
                    this->sumPoints=(this->sumPoints) + 1;
                    return;
                }
            }
        }

        cout<<"The Settlement can not be added to: "<< this->name<<endl;  
    }

    void Player::addCity() { // Requires: 3 Ore & 2 Grain
        int OreSum = 0, GrainSum = 0;
        int indexOre = 0, indexGrain = 0;

        for(size_t i=0; i<this->returnRes.size(); i++){
            if(this->returnRes[i]==ReturnRes::Brick){
                OreSum++;
                indexOre = i;
            }
            if(this->returnRes[i]==ReturnRes::Lumber){
                GrainSum++;
                indexGrain = i;
            }
        }

        if(OreSum>=3 && GrainSum>=2){
            this->settlements.push_back(city()); // We can add a city due to it is heir from settlements
            int checkO = 0, checkG = 0;
            for(size_t i=0; i<this->returnRes.size(); i++){
                if(this->returnRes[i]==ReturnRes::Brick){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkO++;
                }
                if(this->returnRes[i]==ReturnRes::Lumber){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i));
                    checkG++;
                }
            if(checkO==3 && checkG==2){
                    cout<<"A New city has been successfully added to: "<< this->name<<endl;
                    this->sumPoints=(this->sumPoints)+1;
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
        Structure* newRoad = &(this->roads.back()); // Get a pointer to the new road

        // Checking the index of the new road in tile1 and tile2
        size_t indexTile1 = (size_t)-1, indexTile2 = (size_t)-1;
        for(size_t i=0; i<6; i++){
            if(tile1->neighbors[i]==tile2){
                indexTile1 = i;
            }
            if(tile2->neighbors[i]==tile1){
                indexTile2 = i;
            }
        }

        if (indexTile1!=-1 && indexTile2!=-1) { // So the tiles have a share edge
            tile1->edges.insert(tile1->edges.begin() + static_cast<std::vector<Structure*>::difference_type>(indexTile1), newRoad); // The newRoad will be at indexTile1
            tile2->edges.insert(tile1->edges.begin() + static_cast<std::vector<Structure*>::difference_type>(indexTile2), newRoad);
        } else {
            cerr << "Error: The tiles do not share an edge." << endl;
        }

        addRoad(); // Checking the required resources and add a new road
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
            
        cerr << "Error: The tiles do not share an edge." << endl;
        return false;
    }

    void Player::placeSettelemnts(vector<string> places, vector<int> placesNum){
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
        size_t indexTile1 = (size_t)-1, indexTile2 = (size_t)-1, indexTile3 = (size_t)-1;
        for(size_t i=0; i<6; i++){
            if(tile1->neighbors[i] == tile2 || tile1->neighbors[i] == tile3) { // tile1
                indexTile1 = i;
            }
            if(tile2->neighbors[i] == tile1 || tile2->neighbors[i] == tile3) { // tile2
                indexTile2 = i;
            }
            if(tile3->neighbors[i] == tile1 || tile3->neighbors[i] == tile2) { // tile3
                indexTile3 = i;
            }
        }

        if (indexTile1!=(size_t)-1 && indexTile2!=(size_t)-1 && indexTile3!=(size_t)-1) {
            tile1->vertices.insert(tile1->vertices.begin() + static_cast<vector<Structure*>::difference_type>(indexTile1), newSettlement);
            tile2->vertices.insert(tile2->vertices.begin() + static_cast<vector<Structure*>::difference_type>(indexTile2), newSettlement);
            tile3->vertices.insert(tile3->vertices.begin() + static_cast<vector<Structure*>::difference_type>(indexTile3), newSettlement);
        } else {
            cerr << "Error: The tiles do not share an vertex." << endl;
        }
    }

    void Player::placeCity(Tile* tile1, Tile* tile2, Tile* tile3){
        addCity(); // Checking the required resources and add a new City
        Structure* newCity = &(this->cities.back()); // Get a pointer to the new City

        // Checking the index of the new City in tile1, tile2 and tile3
        size_t indexTile1 = (size_t)-1, indexTile2 = (size_t)-1, indexTile3 = (size_t)-1;
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

                tile1->vertices.insert(tile1->vertices.begin() + static_cast<std::vector<Structure*>::difference_type>(indexTile1), newCity); // The newCity will be at indexTile1
                tile2->vertices.insert(tile1->vertices.begin() + static_cast<std::vector<Structure*>::difference_type>(indexTile2), newCity);
                tile3->vertices.insert(tile1->vertices.begin() + static_cast<std::vector<Structure*>::difference_type>(indexTile3), newCity);
            }
        } else {
            cerr << "Error: The tiles do not share an vertex." << endl;
        }
    }

// -----------------------------Game Logic-----------------------------
    // void Player::rollDiceReturnRes(Catan* game, int num){
    //     ReturnRes R;
    //     string tileName;
    //     // Run over all the tiles in the board
    //     for (size_t j=0; j<34; j++) {
    //         for(size_t i=0; i<6; i++){ // The 6 vertices = settlement/city
    //             for(size_t p=0; p<3; p++){ // All the players
    //                 for(size_t s=0; s<game->getPlayers()[i].settlements.size(); s++){ // Run over all the settlements
    //                     // Check if there is a settlement in this vertex and who owns the settlement
    //                     if(game->getBoard().getTiles()[j]->vertices[i]->name    ==    game->getPlayers()[i].settlements[s].name){
    //                         tileName = game->getBoard().getTiles()[j].getTileName();
    //                         if(tileName=="Hills"){
    //                             R = ReturnRes::Brick;
    //                         } else if(tileName=="Forest"){
    //                             R = ReturnRes::Lumber;
    //                         } else if(tileName=="Mountains"){
    //                             R = ReturnRes::Ore;
    //                         } else if(tileName=="Fields"){
    //                             R = ReturnRes::Grain;
    //                         } else if(tileName=="Pasture"){
    //                             R = ReturnRes::Wool;
    //                         }
    //                         game->getPlayers()[i].returnRes.push_back(R);
    //                     }
    //                 }
    //                 for(size_t c=0; c<game->getPlayers()[i].cities.size(); c++){ // Run over all the cities
    //                     if(game->getBoard().getTiles()[j]->vertices[i]->name    ==    game->getPlayers()[i].cities[c].name){
    //                         ResourceTile rst = game.getBoard().getTiles()[j]->tileResource;
    //                         tileName = game.getBoard().getTiles()[j].getTileName(rst);
    //                         if(tileName=="Hills"){
    //                             R = ReturnRes::Brick;
    //                         } else if(tileName=="Forest"){
    //                             R = ReturnRes::Lumber;
    //                         } else if(tileName=="Mountains"){
    //                             R = ReturnRes::Ore;
    //                         } else if(tileName=="Fields"){
    //                             R = ReturnRes::Grain;
    //                         } else if(tileName=="Pasture"){
    //                             R = ReturnRes::Wool;
    //                         }
    //                         // If there is a city, the player get the returnRes twice
    //                         game->getPlayers()[i].returnRes.push_back(R);
    //                         game->getPlayers()[i].returnRes.push_back(R);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    void Player::rollDice(Catan* game) {

        // Generate two random numbers between 1 and 6 (inclusive) for two dice
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        // switch (dice1 + dice2) {
        //     case 2:
        //         rollDiceReturnRes(game, {2});
        //         break;
        //     case 3:
        //         rollDiceReturnRes(game, {3});
        //         break;
        //     case 4:
        //         rollDiceReturnRes(game, {4});
        //         break;
        //     case 5:
        //         rollDiceReturnRes(game, {5});
        //         break;
        //     case 6:
        //         rollDiceReturnRes(game, {6});
        //         break;
        //     case 7:
        //         rollDiceReturnRes(game, {7});
        //         break;
        //     case 8:
        //         rollDiceReturnRes(game, {8});
        //         break;
        //     case 9:
        //         rollDiceReturnRes(game, {9});
        //         break;
        //     case 10:
        //         rollDiceReturnRes(game, {10});
        //         break;
        //     case 11:
        //         rollDiceReturnRes(game, {11});
        //         break;
        //     case 12:
        //         rollDiceReturnRes(game, {12});
        //         break;
        //     default:
        //         cout << "Invalid dice roll!" << endl;
        // }

        // Output the results
        cout << "Dice 1: " << dice1 << endl;
        cout << "Dice 2: " << dice2 << endl;
        cout << "Total: " << dice1 + dice2 << endl;
    }

    // For example: p1 trades 1 wood (str1) for 1 brick (str2) with p2.
    void Player::trade(Player& p2, string str1, string str2, int numOfStr1, int numOfStr2){
        ReturnRes R1, R2;
        R1 = Player::fromStringToRes(str1);
        R2 = Player::fromStringToRes(str2);

        for(size_t i=0; i<this->returnRes.size(); i++){ // str1 going to p2
            if(this->returnRes[i] == R1){
                this->returnRes.erase(this->returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i)); // Remove it from p1
                p2.returnRes.push_back(R1); // Give it to p2
            }
        }

        for(size_t i=0; i<p2.returnRes.size(); i++){ // str2 going to p1
            if(p2.returnRes[i] == R2){
                p2.returnRes.erase(p2.returnRes.begin() + static_cast<std::vector<ReturnRes>::difference_type>(i)); // Remove it from p2
                this->returnRes.push_back(R2); // Give it to p1
            }
        }

        cout << "trade success: ";
        cout << this->name << " get " << numOfStr2 << " of " << str2;
        cout << " and " << p2.name << " get " << numOfStr1 << " of " << str1 << endl;
    }

    void Player::endTurn(){
        this->turn = false;
    }

    void Player::buyDevelopmentCard(){
        bool checkOre=false, checkGrain=false, checkWool=false;
        VictoryPointCard* card = nullptr; // Initialize card pointer
        // First, let's check if p2 has the resources needed for buing a development card
        for(size_t i=0; i<this->returnRes.size(); i++){
            if(Player::Resto_string(this->returnRes[i]) == "Ore"){
                checkOre = true;
            }
            else if(Player::Resto_string(this->returnRes[i]) == "Grain"){
                checkGrain = true;
            }
            else if(Player::Resto_string(this->returnRes[i]) == "Wool"){
                checkWool = true;
            }
        }

        if (checkOre && checkGrain && checkWool) { // p2 can buy a development card
            card = new VictoryPointCard(); // Allocate memory for the card
            this->DevelopmentCards.push_back(card); // Add the new card to p2
            for(size_t i=0; i<this->returnRes.size(); i++){ // Payment
                if(((Player::Resto_string(this->returnRes[i])) == "Ore") && (checkOre=true)){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<vector<ReturnRes>::difference_type>(i));
                    checkOre = false; // To verify a one-time payment
                }
                else if(((Player::Resto_string(this->returnRes[i])) == "Grain") && (checkGrain=true)){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<vector<ReturnRes>::difference_type>(i));
                    checkGrain = false;
                }
                else if(((Player::Resto_string(this->returnRes[i])) == "Wool") && (checkWool==true)){
                    this->returnRes.erase(this->returnRes.begin() + static_cast<vector<ReturnRes>::difference_type>(i));
                    checkWool = false;
                }
            }

            cout << this->name << " buy a new "<< card->getCardName() << "card." << endl;
        }
    }

    void Player::useMonopolyCard(Catan* game, Player& p) {
        vector<Player> players = game->getPlayers();
        ReturnRes takenRes; // The resource the player want to take

        int sumTakenRes = 0;

        for (size_t i = 0; i < players.size(); i++) {
            Player& player = players[i];
            for (size_t j = 0; j < player.returnRes.size(); j++) {
                while (player.returnRes[j] == takenRes) {
                    sumTakenRes++;
                    player.returnRes.erase(player.returnRes.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(j)); // Remove the resource from the player's list
                }
            }
        }

        for(size_t i=0;  i<(size_t)sumTakenRes; i++){ // Add to p all the taken resources
            p.returnRes.push_back(takenRes);
        }

        // Remove the Development Card after use
        size_t needBeRemove = findIndex(p.DevelopmentCards, CardType::Monopoly);
        p.DevelopmentCards.erase(p.DevelopmentCards.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(needBeRemove));

        cout<<p.name<< " get "<<sumTakenRes << " of "<< Player::Resto_string(takenRes)<<endl;
    }

    void Player::useBuildingRoadsCard(Player& p) {
        string tile1String, tile2String, tile3String, tile4String;
        ResourceType R1, R2, R3, R4;
        int t1, t2, t3, t4;
        cout << "Enter 2 tiles for the first rooad: ";
        cin >> tile1String;
        cin >> t1;
        cin >> tile2String;
        cin >> t2;

        cout << "Enter 2 tiles for the seconed rooad: ";
        cin >> tile3String;
        cin >> t3;
        cin >> tile4String;
        cin >> t4;

        // ResourceType { Hills, Forest, Mountains, Fields, Pasture, Desert, Sea };
            if(tile1String=="Hills"){
                R1 = ResourceType::Hills;
            } else if(tile1String=="Forest"){
                R1 = ResourceType::Forest;
            } else if(tile1String=="Mountains"){
                R1 = ResourceType::Mountains;
            } else if(tile1String=="Fields"){
                R1 = ResourceType::Fields;
            } else if(tile1String=="Pasture"){
                R1 = ResourceType::Pasture;
            } else if(tile1String=="Desert"){
                R1 = ResourceType::Desert;
            } else if(tile1String=="Sea"){
                R1 = ResourceType::Sea;
            }

            if(tile2String=="Hills"){
                R2 = ResourceType::Hills;
            } else if(tile2String=="Forest"){
                R2 = ResourceType::Forest;
            } else if(tile2String=="Mountains"){
                R2 = ResourceType::Mountains;
            } else if(tile2String=="Fields"){
                R2 = ResourceType::Fields;
            } else if(tile2String=="Pasture"){
                R2 = ResourceType::Pasture;
            } else if(tile2String=="Desert"){
                R2 = ResourceType::Desert;
            } else if(tile2String=="Sea"){
                R2 = ResourceType::Sea;
            }

            if(tile3String=="Hills"){
                R3 = ResourceType::Hills;
            } else if(tile3String=="Forest"){
                R3 = ResourceType::Forest;
            } else if(tile3String=="Mountains"){
                R3 = ResourceType::Mountains;
            } else if(tile3String=="Fields"){
                R3 = ResourceType::Fields;
            } else if(tile3String=="Pasture"){
                R3 = ResourceType::Pasture;
            } else if(tile3String=="Desert"){
                R3 = ResourceType::Desert;
            } else if(tile3String=="Sea"){
                R3 = ResourceType::Sea;
            }

            if(tile4String=="Hills"){
                R4 = ResourceType::Hills;
            } else if(tile4String=="Forest"){
                R4 = ResourceType::Forest;
            } else if(tile4String=="Mountains"){
                R4 = ResourceType::Mountains;
            } else if(tile4String=="Fields"){
                R4 = ResourceType::Fields;
            } else if(tile4String=="Pasture"){
                R4 = ResourceType::Pasture;
            } else if(tile4String=="Desert"){
                R4 = ResourceType::Desert;
            } else if(tile4String=="Sea"){
                R4 = ResourceType::Sea;
            }


            Tile* tile1 = new Tile(R1, t1);
            Tile* tile2 = new Tile(R2, t2);
            Tile* tile3 = new Tile(R3, t3);
            Tile* tile4 = new Tile(R4, t4);

        p.placeRoad(tile1, tile2);
        p.placeRoad(tile3, tile4);

        // Remove the Development Card after use
        size_t needBeRemove = findIndex(p.DevelopmentCards, CardType::BuildingRoads);
        p.DevelopmentCards.erase(p.DevelopmentCards.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(needBeRemove));

        cout << "Building Roads: Build 2 roads without any resource payment." << endl;
    }

    void Player::useYearOfAbundanceCard(Player& p) {
        string R1, R2;
        ReturnRes Res1, Res2;
        cout << " Choose 2 resources from the checkout: ";
        cin >> R1;
        cin >> R2;

        // ReturnRes {Lumber, Brick, Wool, Grain, Ore};
        if(R1=="Lumber"){
            Res1 = ReturnRes::Lumber;
            p.returnRes.push_back(Res1);
        } else if(R1=="Brick"){
            Res1 = ReturnRes::Brick;
            p.returnRes.push_back(Res1);
        } else if(R1=="Wool"){
            Res1 = ReturnRes::Wool;
            p.returnRes.push_back(Res1);
        } else if(R1=="Grain"){
            Res1 = ReturnRes::Grain;
            p.returnRes.push_back(Res1);
        } else if(R1=="Ore"){
            Res1 = ReturnRes::Ore;
            p.returnRes.push_back(Res1);
        }

        if(R2=="Lumber"){
            Res2 = ReturnRes::Lumber;
            p.returnRes.push_back(Res2);
        } else if(R2=="Brick"){
            Res2 = ReturnRes::Brick;
            p.returnRes.push_back(Res2);
        } else if(R2=="Wool"){
            Res2 = ReturnRes::Wool;
            p.returnRes.push_back(Res2);
        } else if(R2=="Grain"){
            Res2 = ReturnRes::Grain;
            p.returnRes.push_back(Res2);
        } else if(R2=="Ore"){
            Res2 = ReturnRes::Ore;
            p.returnRes.push_back(Res2);
        }

        // Remove the Development Card after use
        size_t needBeRemove = findIndex(p.DevelopmentCards, CardType::YearOfAbundance);
        p.DevelopmentCards.erase(p.DevelopmentCards.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(needBeRemove));

        cout << p.name << "chose: " << R1 << " and " << R2 << endl;
    }

    void Player::useKnightCard(Catan* game, Player& p) {
        p.sumOfKnights = p.sumOfKnights++; // Add one more knight to p
        int TheBigArmy = 0;
        Player* biggestKnight; // Pointer to the player which has the biggest army

        vector<Player> players = game->getPlayers(); // All the players of the game

        for(size_t i=0; i<players.size()-1; i++){ // Checking how has the biggest army
            if(players[i].sumOfKnights > players[i+1].sumOfKnights){
                biggestKnight = &players[i]; // Update the pointer
                TheBigArmy = players[i].sumOfKnights; // The sum of the largest army
            }
        }

        // P has the lergest army than the others OR his army >=3
        if(p.sumOfKnights>TheBigArmy || (TheBigArmy<3 && p.sumOfKnights>=3)){
            p.sumPoints = p.sumPoints + 2; // 2 points more
            cout << p.name << "has the largest army! and gets 2 points" << endl;
        }
        else{
            biggestKnight->sumPoints = biggestKnight->sumPoints + 2;
            cout << biggestKnight->name << "has the largest army! and gets 2 points" << endl;
        }

        // Remove the Development Card after use
        size_t needBeRemove = findIndex(p.DevelopmentCards, CardType::Knight);
        p.DevelopmentCards.erase(p.DevelopmentCards.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(needBeRemove));
    }

    void Player::useVictoryPointCard(Player& p) {
        p.sumPoints = p.sumPoints+1;

        // Remove the Development Card after use
        size_t needBeRemove = findIndex(p.DevelopmentCards, CardType::VictoryPoint);
        p.DevelopmentCards.erase(p.DevelopmentCards.begin() + static_cast<std::vector<DevelopmentCard>::difference_type>(needBeRemove));

        cout << p.name << "get a Victory Point." << endl;
    }




    void Player::printPoints(){
        cout << this->name << " has "<< this->sumPoints << " points." << endl;
    }
