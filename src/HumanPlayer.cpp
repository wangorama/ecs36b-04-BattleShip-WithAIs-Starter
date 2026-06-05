//
// Created by kingdoofus on 5/20/26.
//

#include "HumanPlayer.h"
namespace BattleShip {

        /**
             * Get a valid firing location from this player to shoot
             * @param in : the stream to get input from
             * @param out : the stream to display output to
             * @return : a valid location to shoot out in the form row, col
             */
        std::pair<int, int> HumanPlayer::get_firing_location(std::istream& in, std::ostream& out) {
            //HumanPlayer does the said function
            const std::string prompt = std::format(
                "{}, where would you like to fire?\n"
                "Enter your attack coordinate in the form row col:",
                name());

            out << std::format("{}'s Firing Board\n{}\n\n", name(), opponent().board_.view_as_hidden());
            out << std::format("{}'s Placement Board\n{}\n", name(), board_.view_as_visible());
            while (true) {
                auto possible_row_and_col = get_row_and_column(prompt, in, out);
                if (not possible_row_and_col.has_value()) {
                    continue; //ask again
                }
                auto [row,col] = possible_row_and_col.value();
                if (not board_.is_on(row, col)) {
                    continue; //ask again
                }
                if (opponent().board_.has_been_fired_at(row, col)) {
                    continue; //ask again
                }
                return std::make_pair(row, col);
            }
        }

    void HumanPlayer::place_ships(std::istream& in, std::ostream& out) {
            for (const auto [ship_name, ship_health]: ship_healths_) {
                out << board_.view_as_visible() << std::endl;
                place_ship(ship_name, ship_health, in, out);
                out << board_.view_as_visible() << std::endl;
            }
        }

    void HumanPlayer::place_ship(const char ship_name, const int ship_length, std::istream& in, std::ostream& out) {
            while (true) {
                auto orientation = get_orientation(ship_name, in, out);
                if (not orientation.has_value()) {
                    continue;
                }
                const auto placement = get_placement(ship_name, ship_length, orientation.value(), in, out);
                if (placement.has_value()) {
                    board_.place_ship(placement.value());
                    return;
                }
            }
        }


}