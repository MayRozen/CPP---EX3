/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>
#include "Tile.cpp"
#include "Structure.cpp"
#include "player.hpp"
using namespace std;

namespace ariel{

    void Player::addRoad(Player p) {  // Requires: Brick & Lumber
        int BrickSum = 0, LumberSum = 0;
        int indexBrick = 0, indexLumber = 0;
        vector<ReturnRes> r = p.returnRes;

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
            p.settlements.push_back(road()); // We can add a road due to it is heir from settlements
            int checkB = 0, checkL = 0;
            for(size_t i=0; i<r.size(); i++){
                if(checkB!=1 && r[i]==ReturnRes::Brick){
                    p.returnRes.erase(r.begin()+i);
                    checkB = 1;
                }
                if(checkL!=1 && r[i]==ReturnRes::Lumber){
                    p.returnRes.erase(r.begin()+i);
                    checkL = 1;
                }
                if(checkB==1 && checkL==1){
                    cout<<"A New rode has been successfully added to: "<< p.name<<endl;
                    break;
                }
            }
        }

        cout<<"The rode can not be added to: "<< p.name<<endl; 
    }

    void Player::addSettlement(Player p) { // Requires: Brick, Lumber, Wool, & Grain
        int BrickSum = 0, LumberSum = 0, WoolSum = 0, GrainSum = 0;
        int indexBrick = 0, indexLumber = 0, indexWool = 0, indexGrain = 0;
        vector<ReturnRes> r = p.returnRes;

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
            p.settlements.push_back(settlement()); // We can add a settlement due to it is heir from settlements
            int checkB = 0, checkL = 0, checkW = 0, checkG = 0;
            for(size_t i=0; i<r.size(); i++){
                if(r[i]==ReturnRes::Brick){
                    p.returnRes.erase(r.begin()+i);
                    checkB = 1;
                }
                if(r[i]==ReturnRes::Lumber){
                    p.returnRes.erase(r.begin()+i);
                    checkL = 1;
                }
                if(r[i]==ReturnRes::Wool){
                    p.returnRes.erase(r.begin()+i);
                    checkW = 1;
                }
                if(r[i]==ReturnRes::Grain){
                    p.returnRes.erase(r.begin()+i);
                    checkG = 1;
                }
            if(checkB==1 && checkL==1 && checkW==1 && checkG ==1){
                    cout<<"A New Settlement has been successfully added to: "<< p.name<<endl;
                    break;
                }
            }
        }

        cout<<"The Settlement can not be added to: "<< p.name<<endl;  
    }

    void Player::addCity(Player p) { // Requires: 3 Ore & 2 Grain
        int OreSum = 0, GrainSum = 0;
        int indexOre = 0, indexGrain = 0;
        vector<ReturnRes> r = p.returnRes;

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
            p.settlements.push_back(city()); // We can add a city due to it is heir from settlements
            int checkO = 0, checkG = 0;
            for(size_t i=0; i<r.size(); i++){
                if(r[i]==ReturnRes::Brick){
                    p.returnRes.erase(r.begin()+i);
                    checkO++;
                }
                if(r[i]==ReturnRes::Lumber){
                    p.returnRes.erase(r.begin()+i);
                    checkG++;
                }
            if(checkO==3 && checkG==2){
                    cout<<"A New city has been successfully added to: "<< p.name<<endl;
                    break;
                }
            }
        }

        cout<<"The city can not be added to: "<< p.name<<endl;  
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
}
