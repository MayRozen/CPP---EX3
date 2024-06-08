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

void MonopolyCard::useCard() {
    cout << "Monopoly: Take one resource type from all other players." << endl;
}

// -----------------------------BuildingRoadsCard-----------------------------
CardType BuildingRoadsCard::getType() const {
    return CardType::BuildingRoads;
}

string BuildingRoadsCard::getCardName() const {
    return "Building Roads";
}

void BuildingRoadsCard::useCard() {
    cout << "Building Roads: Build 2 roads without any resource payment." << endl;
}

// -----------------------------YearOfAbundanceCard-----------------------------
CardType YearOfAbundanceCard::getType() const {
    return CardType::YearOfAbundance;
}

string YearOfAbundanceCard::getCardName() const {
    return "Year Of Abundance";
}

void YearOfAbundanceCard::useCard() {
    cout << "Year Of Abundance: Choose 2 resources without any resource payment." << endl;
}

// -----------------------------KnightCard-----------------------------
CardType KnightCard::getType() const {
    return CardType::Knight;
}

string KnightCard::getCardName() const {
    return "Knight";
}

void KnightCard::useCard() {
    cout << "Knight: Move the robber." << endl;
}

// -----------------------------VictoryPointCard-----------------------------
CardType VictoryPointCard::getType() const {
    return CardType::VictoryPoint;
}

string VictoryPointCard::getCardName() const {
    return "Victory Point";
}

void VictoryPointCard::useCard() {
    cout << "Victory Point: Gain 1 victory point." << endl;
}

} // namespace ariel
