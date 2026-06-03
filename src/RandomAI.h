//
// Created by kingdoofus on 5/20/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_RANDOMAI_H
#define ECS36BBATTLESHIPWITHAI_RANDOMAI_H
#include "AIPlayer.h"

namespace BattleShip {
    class RandomAI: public AIPlayer {
        //randomly generates the move and go blind

    public:
        virtual std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override; //the random generator of it



    };
}



#endif //ECS36BBATTLESHIPWITHAI_RANDOMAI_H
