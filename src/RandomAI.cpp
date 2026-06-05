//
// Created by kingdoofus on 5/20/26.
//

#include "RandomAI.h"
namespace BattleShip {
    RandomAI::RandomAI(const std::string& name, const GameConfig& game_config)
    : AIPlayer(name, game_config) {
        for (int row = 0; row < game_config.board_num_rows(); row++) {
            for (int col = 0; col < game_config.board_num_cols(); col++) {
                positions_.push_back({row, col});
            }
        }
    }

    void RandomAI::place_ships(std::istream& in, std::ostream& out) {
        AIPlayer::place_ships(in, out);
        std::ranges::shuffle(positions_, rng_);
    }

    std::pair<int,int> RandomAI::get_firing_location(std::istream& in, std::ostream& out) {
        auto location = positions_.back();
        positions_.pop_back();
        return location;
    }
}