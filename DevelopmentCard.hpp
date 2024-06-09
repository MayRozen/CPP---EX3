/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>
#include <string>
#include "catan.hpp"
#include "Tile.cpp"
using namespace std;

/*
1   Monopoly -> can take one resourceType from all the other players
    BuildingRoads -> build 2 roads without any resourceType payment
    YearOfAbundance -> can choose 2 resourceType without any resourceType payment

2   Knight -> need 3 cards for 2 points

3   VictoryPoint -> there is 4 cards and every one can give 1 point
*/

namespace ariel {
enum class CardType {
    Monopoly,
    BuildingRoads,
    YearOfAbundance,
    Knight,
    VictoryPoint
};

string toString(CardType type) {
    switch(type) {
        case CardType::Monopoly:
            return "Monopoly";
        case CardType::BuildingRoads:
            return "Building Roads";
        case CardType::YearOfAbundance:
            return "Year of Abundance";
        case CardType::Knight:
            return "Knight";
        case CardType::VictoryPoint:
            return "Victory Point";
        default:
            return "Unknown";
    }
}

class DevelopmentCard {
public:
    virtual ~DevelopmentCard() {}
    virtual CardType getType() const = 0;
    virtual string getCardName() const = 0;
    virtual void useCard(Player& p) = 0;
};

// -----------------------------MonopolyCard-----------------------------
class MonopolyCard : public DevelopmentCard {
public:
    CardType getType() const override { return CardType::Monopoly; }

    string getCardName() const override { return "Monopoly"; }

    void useCard(Player& p) override;
};

// -----------------------------BuildingRoadsCard-----------------------------
class BuildingRoadsCard : public DevelopmentCard {
public:
    CardType getType() const override { return CardType::BuildingRoads; }
    string getCardName() const override { return "Building Roads"; }
    void useCard(Player& p) override;
};

// -----------------------------YearOfAbundanceCard-----------------------------
class YearOfAbundanceCard : public DevelopmentCard {
public:
    CardType getType() const override { return CardType::YearOfAbundance; }
    string getCardName() const override { return "Year Of Abundance"; }
    void useCard(Player& p) override;
};

// -----------------------------KnightCard-----------------------------
class KnightCard : public DevelopmentCard {
public:
    CardType getType() const override { return CardType::Knight; }
    string getCardName() const override { return "Knight"; }
    void useCard(Player& p) override;
};

// -----------------------------VictoryPointCard-----------------------------
class VictoryPointCard : public DevelopmentCard {
public:
    CardType getType() const override { return CardType::VictoryPoint; }
    string getCardName() const override { return "Victory Point"; }
    void useCard(Player& p) override;
};

} // namespace ariel

#endif // DEVELOPMENTCARD_HPP
