//
// Created by kingdoofus on 6/1/26.
//

#include "CheatingAI.h"

namespace BattleShip {

        CheatingAI::CheatingAI(const std::string& name, const GameConfig& game_config):AIPlayer(name, game_config){}

        std::pair<int, int> CheatingAI::get_firing_location(std::istream& in, std::ostream& out) {
            for (int row = 0; row < opponent().board().num_rows(); row++) {
                for (int col = 0; col < opponent().board().num_cols(); col++) {
                    if (opponent().board().has_ship_at(row, col) &&
                        !opponent().board().has_been_fired_at(row, col)) {
                        return {row, col};
                        }
                }
            }

        } //use the cross reference of a players board to attack
}