//
// Created by kingdoofus on 6/1/26.
//

#include "SearchandDestroyAI.h"


namespace BattleShip {
    SearchAndDestroyAI::SearchAndDestroyAI(const std::string &name, const GameConfig &game_config):RandomAI(name, game_config)  {


    }
    std::pair<int, int> SearchAndDestroyAI::get_firing_location(std::istream& in, std::ostream& out) {
        if (destroy_queue_.empty()) {
            return RandomAI::get_firing_location(in, out);
        }  else {
            auto location = destroy_queue_.front();
            destroy_queue_.pop_front();
            return location;
        }
    }

    void SearchAndDestroyAI::notify_hit(int row, int col) {
        process_hit(row, col);
    }

    void SearchAndDestroyAI::process_hit(int row, int col) {
        // check left, up, right, down in that order
        const std::vector<std::pair<int,int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        for (auto [dr, dc] : directions) {
            int new_row = row + dr;
            int new_col = col + dc;
            if (opponent().board().is_on(new_row, new_col) &&
                !opponent().board().has_been_fired_at(new_row, new_col) &&
                std::ranges::find(destroy_queue_, std::make_pair(new_row, new_col)) == destroy_queue_.end()
            ) {
                destroy_queue_.push_back({new_row, new_col});
            }
        }
    }
}