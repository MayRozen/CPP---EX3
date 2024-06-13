/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include "DevelopmentCard.hpp"
#include "catan.cpp"
using namespace std;

// -----------------------------MonopolyCard-----------------------------
CardType MonopolyCard::getType() const {
    return CardType::Monopoly;
}

string MonopolyCard::getCardName() const {
    return "Monopoly";
}

// -----------------------------BuildingRoadsCard-----------------------------
CardType BuildingRoadsCard::getType() const {
    return CardType::BuildingRoads;
}

string BuildingRoadsCard::getCardName() const {
    return "Building Roads";
}

// -----------------------------YearOfAbundanceCard-----------------------------
CardType YearOfAbundanceCard::getType() const {
    return CardType::YearOfAbundance;
}

string YearOfAbundanceCard::getCardName() const {
    return "Year Of Abundance";
}

// -----------------------------KnightCard-----------------------------
CardType KnightCard::getType() const {
    return CardType::Knight;
}

string KnightCard::getCardName() const {
    return "Knight";
}

// -----------------------------VictoryPointCard-----------------------------
CardType VictoryPointCard::getType() const {
    return CardType::VictoryPoint;
}

string VictoryPointCard::getCardName() const {
    return "Victory Point";
}
