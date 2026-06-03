//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_AIPLAYER_H
#define ECS36BBATTLESHIPWITHAI_AIPLAYER_H
#include <iosfwd>
#include <random>
#include <utility>

#include "Player.h"


namespace BattleShip {
    class AIPlayer: public Player {
        static std::mt19937 rng;

        void place_ships(std::istream &in, std::ostream &out) override;

        std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override;

        virtual ~AIPlayer() = default;
    };
}

#endif //ECS36BBATTLESHIPWITHAI_AIPLAYER_H
