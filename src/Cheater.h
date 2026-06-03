//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_CHEATER_H
#define ECS36BBATTLESHIPWITHAI_CHEATER_H
#include "AIPlayer.h"


namespace BattleShip {
    class Cheater : public AIPlayer {
        //need a reference of the humanplayers board
        void readPlayerBoard(); //to crossreference the board from the player

        virtual std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override; //use the cross reference to attack

    };
}


#endif //ECS36BBATTLESHIPWITHAI_CHEATER_H
