//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_AIPLAYER_H
#define ECS36BBATTLESHIPWITHAI_AIPLAYER_H
#include <iosfwd>
#include <random>
#include <utility>
#include <vector>

#include "Player.h"


namespace BattleShip {
    class AIPlayer: public Player {
        static void seed(unsigned int seed);

        void place_ships(std::istream &in, std::ostream &out) override;

        virtual std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override = 0;

        virtual ~AIPlayer() = default;
    private:
        std::vector<std::pair<int, int>> Firing_Locations;
    };
}

#endif //ECS36BBATTLESHIPWITHAI_AIPLAYER_H
