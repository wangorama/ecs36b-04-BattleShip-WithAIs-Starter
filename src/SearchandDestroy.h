//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
#define ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
#include "Cheater.h"
#include "RandomAI.h"

namespace BattleShip {
    class SearchandDestroy : public RandomAI {
        //this is a deadly diamond problem
        //randomAI is ran first to randomly hit your ship
        //then if it hits any of what the cheater read, attack from the left to right or up to down

    };
}



#endif //ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
