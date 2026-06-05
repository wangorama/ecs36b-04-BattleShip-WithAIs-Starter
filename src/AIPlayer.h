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
    class AIPlayer : public Player {
    public:

        // no keyboard input needed, just a name and game config
        AIPlayer(const std::string& name, const GameConfig& game_config);

        void place_ships(std::istream& in, std::ostream& out) override;

        static void seed_rng(unsigned int seed) { rng_.seed(seed); }

        // pure virtual since each AI shoots differently
        std::pair<int,int> get_firing_location(std::istream& in, std::ostream& out) override = 0;

    protected:
        static std::mt19937 rng_; // one generator shared by all AIs
    };
}

#endif //ECS36BBATTLESHIPWITHAI_AIPLAYER_H
