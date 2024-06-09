/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include "DevelopmentCard.hpp"
using namespace std;

namespace ariel {

DevelopmentCard::~DevelopmentCard() {}

// -----------------------------MonopolyCard-----------------------------
CardType MonopolyCard::getType() const {
    return CardType::Monopoly;
}

string MonopolyCard::getCardName() const {
    return "Monopoly";
}

void MonopolyCard::useCard(Player& p) {
            Catan* game = Catan::getInstance();
        vector<Player>& players = game->getPlayers();
        ReturnRes takenRes; // The resource the player want to take

        int sumTakenRes = 0;

        for (size_t i = 0; i < players.size(); i++) {
            Player& player = players[i];
            for (size_t j = 0; j < player.returnRes.size(); j++) {
                while (player.returnRes[j] == takenRes) {
                    sumTakenRes++;
                    player.returnRes.erase(player.returnRes.begin() + j); // Remove the resource from the player's list
                }
            }
        }

        for(size_t i=0;  i<(size_t)sumTakenRes; i++){ // Add to p all the taken resources
            p.returnRes.push_back(takenRes);
        }

        cout<<p.name<< " get "<<sumTakenRes << " of "<< to_string(takenRes)<<endl;
}

// -----------------------------BuildingRoadsCard-----------------------------
CardType BuildingRoadsCard::getType() const {
    return CardType::BuildingRoads;
}

string BuildingRoadsCard::getCardName() const {
    return "Building Roads";
}

void BuildingRoadsCard::useCard(Player& p) {
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
    cout << "Building Roads: Build 2 roads without any resource payment." << endl;
}

// -----------------------------YearOfAbundanceCard-----------------------------
CardType YearOfAbundanceCard::getType() const {
    return CardType::YearOfAbundance;
}

string YearOfAbundanceCard::getCardName() const {
    return "Year Of Abundance";
}

void YearOfAbundanceCard::useCard(Player& p) {
    cout << "Year Of Abundance: Choose 2 resources without any resource payment." << endl;
}

// -----------------------------KnightCard-----------------------------
CardType KnightCard::getType() const {
    return CardType::Knight;
}

string KnightCard::getCardName() const {
    return "Knight";
}

void KnightCard::useCard(Player& p) {
    cout << "Knight: Move the robber." << endl;
}

// -----------------------------VictoryPointCard-----------------------------
CardType VictoryPointCard::getType() const {
    return CardType::VictoryPoint;
}

string VictoryPointCard::getCardName() const {
    return "Victory Point";
}

void VictoryPointCard::useCard(Player& p) {
    cout << "Victory Point: Gain 1 victory point." << endl;
}

} // namespace ariel
