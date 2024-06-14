/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
using namespace std;


int main()
{
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan* CatanGame = Catan::getInstance(p1, p2, p3);
    // Starting of the game. Every player places two settlements and two roads.
    CatanGame->ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board board = CatanGame->getBoard(); // get the board of the game.

    // -----------------------------p1-----------------------------
    vector<string> placesSet = {"Forest", "Hills","Mountains"};
    vector<int> placesSetNum = {3, 10, 8};
    p1.placeSettelemnts(placesSet, placesSetNum);
    p1.returnRes.push_back(ReturnRes::Brick);
    p1.returnRes.push_back(ReturnRes::Lumber);
    p1.returnRes.push_back(ReturnRes::Ore);
    
    vector<string> placesRoad = {"Forest", "Hills"};
    vector<int> placesRoadNum = {3, 10};
    p1.placeRoad(placesRoad, placesRoadNum);
    cout<< "p1 first road success"<<endl;

    placesSet = {"Fields", "Desert", "Forest"};
    placesSetNum = {4, -1, 3};
    p1.placeSettelemnts(placesSet, placesSetNum);
    p1.returnRes.push_back(ReturnRes::Grain);
    p1.returnRes.push_back(ReturnRes::Lumber);

    placesRoad = {"Fields", "Forest"};
    placesRoadNum = {4, 3};
    p1.placeRoad(placesRoad, placesRoadNum);

    // -----------------------------p2-----------------------------
    placesSet = {"Mountains", "Pasture", "Hills"};
    placesSetNum = {10, 2, 6};
    p2.placeSettelemnts(placesSet, placesSetNum);
    p2.returnRes.push_back(ReturnRes::Wool);
    p2.returnRes.push_back(ReturnRes::Brick);
    p2.returnRes.push_back(ReturnRes::Ore);

    placesRoad = {"Mountains", "Pasture"};
    placesRoadNum = {10, 2};
    p2.placeRoad(placesRoad, placesRoadNum);

    try
    {
        p3.placeSettelemnts(placesSet, placesSetNum); // p3 tries to place a settlement in the same location as p2.
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    placesSet = {"Forest", "Forest", "Fields"};
    placesSetNum = {8, 11, 9};
    p2.placeSettelemnts(placesSet, placesSetNum);
    p2.returnRes.push_back(ReturnRes::Brick);
    p2.returnRes.push_back(ReturnRes::Brick);
    p2.returnRes.push_back(ReturnRes::Grain);

    placesRoad = {"Forest", "Forest"};
    placesRoadNum = {8, 11};
    p2.placeRoad(placesRoad, placesRoadNum); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

    // -----------------------------p3-----------------------------
    placesSet = {"Mountains", "Fields", "Fields"};
    placesSetNum = {3, 4, 6};
    p3.placeSettelemnts(placesSet, placesSetNum);
    p3.returnRes.push_back(ReturnRes::Ore);
    p3.returnRes.push_back(ReturnRes::Grain);
    p3.returnRes.push_back(ReturnRes::Grain);

    placesRoad = {"Mountains", "Fields"};
    placesRoadNum = {3, 6};
    p3.placeRoad(placesRoad, placesRoadNum);

    placesSet = {"Pasture", "Pasture", "Fields"};
    placesSetNum = {5, 11, 4};
    p3.placeSettelemnts(placesSet, placesSetNum);
    p3.returnRes.push_back(ReturnRes::Wool);
    p3.returnRes.push_back(ReturnRes::Wool);
    p3.returnRes.push_back(ReturnRes::Grain);

    placesRoad = {"Pasture", "Fields"};
    placesRoadNum = {11, 4};
    p3.placeRoad(placesRoad, placesRoadNum); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

    //p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    p1.rollDice(CatanGame);                                    // Lets say it's print 4. Then, p2 gets ore from the mountations.
    p1.placeRoad({"Forest", "Hills"}, {5, 6}); // p1 continues to build a road.
    p1.endTurn();                                     // p1 ends his turn.

    p2.rollDice(CatanGame); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.endTurn();  // p2 ends his turn.

    p3.rollDice(CatanGame); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    p3.endTurn();  // p3 ends his turn.

    try
    {
        p2.rollDice(CatanGame); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    p1.rollDice(CatanGame);                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.endTurn();                        // p1 ends his turn.

    p2.rollDice(CatanGame);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    p2.endTurn();            // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because it has two settelments.
    p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settelments.

    CatanGame->printWinner(); // Should print None because no player reached 10 points.
}
