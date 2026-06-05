//
// Created by kingdoofus on 6/1/26.
//

#include "AIPlayer.h"

std::mt19937 AIPlayer::rng_;

namespace BattleShip {
    AIPlayer::AIPlayer(const std::string& name, const GameConfig& game_config)
    : Player(name, game_config.board(), game_config.ship_healths(), nullptr) {}



    void AIPlayer::place_ships(std::istream& in, std::ostream& out) {
            for (const auto [ship_name, ship_health]: ship_healths_) {
                out << board_.view_as_visible() << std::endl;
                place_ship(ship_name, ship_health, in, out);
                out << board_.view_as_visible() << std::endl;
            }
        }

    void AIPlayer::place_ship(const char ship_name, const int ship_length, std::istream& in, std::ostream& out) {
            while (true) {
                Orientation orientation = std::uniform_int_distribution<int>(0, 1)(rng_) == 0 ? Orientation::HORIZONTAL : Orientation::VERTICAL;
                int max_row = orientation == Orientation::HORIZONTAL ? board_.num_rows() - 1 : board_.num_rows() - ship_length;
                int max_col = orientation == Orientation::HORIZONTAL ? board_.num_cols() - ship_length : board_.num_cols() - 1;
                int row = std::uniform_int_distribution<int>(0, max_row)(rng_);
                int col = std::uniform_int_distribution<int>(0, max_col)(rng_);

                ShipPlacement placement(ship_name, ship_length, row, col, orientation);
                if (board_.can_ship_be_placed(placement)) {
                    board_.place_ship(placement);
                    return;
                }
            }
        }
}