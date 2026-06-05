//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_CHEATER_H
#define ECS36BBATTLESHIPWITHAI_CHEATER_H
#include "AIPlayer.h"


namespace BattleShip {
    class CheatingAI : public AIPlayer {
    public:
        CheatingAI(const std::string& name, const GameConfig& game_config);
        std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override; //use the cross reference of a players board to attack

    };
}


#endif //ECS36BBATTLESHIPWITHAI_CHEATER_H
 