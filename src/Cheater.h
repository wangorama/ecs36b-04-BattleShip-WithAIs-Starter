//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_CHEATER_H
#define ECS36BBATTLESHIPWITHAI_CHEATER_H
#include "AIPlayer.h"


namespace BattleShip {
    class Cheater : public AIPlayer {
        //need a reference of the humanplayers board
        void readPlayerBoard();

        void attack();

    };
}


#endif //ECS36BBATTLESHIPWITHAI_CHEATER_H
