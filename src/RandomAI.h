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
        RandomAI(const std::string& name, const GameConfig& game_config);
        void place_ships(std::istream& in, std::ostream& out) override;
        std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override; //the random generator of it
    private:
        std::vector<std::pair<int,int>> positions_;
    };


}



#endif //ECS36BBATTLESHIPWITHAI_RANDOMAI_H
