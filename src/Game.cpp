//
// Created by mfbut on 4/24/2026.
//

#include "Game.h"

#include <algorithm>
#include <format>

#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "SearchAndDestroyAI.h"

namespace BattleShip {
    /**
     * Create a game based on the game configuration
     * @param game_config : The configuration for this game
     * @param in : the stream to get input from
     * @param out : the stream to display output to
     */

    int Game::gameSelect(std::istream& in, std::ostream& out) {
        //this makes the selection
        int choice = 0;
        out << "What type of game do you want to play?\n";
        out << "1. Human vs Human\n";
        out << "2. Human vs AI\n";
        out << "3. AI vs AI\n";
        in >> choice;
        return choice;
        }

    int Game::aiSelect(std::istream& in, std::ostream& out) {
        int choice = 0;
        out<<"What AI do you want?\n";
        out << "1. Cheating AI\n";
        out << "2. Random AI\n";
        out << "3. Search and Destroy AI\n";
        in >> choice;
        return choice;}



    Game::Game(const GameConfig& game_config, std::istream& in, std::ostream& out) : players_(), cur_player_index_(0),
        in_(in), out_(out) {
        int choice = gameSelect(in, out);
        if (choice == 1) {
            const int num_players = 2;
            for (int i = 0; i < num_players; ++i) {
                players_.push_back(std::make_unique<HumanPlayer>(game_config, in, out, players_));
                players_.at(i)->place_ships(in_, out_);
            }

            for (int i = 0; i < num_players; ++i) {
                players_.at(i)->set_opponent(*players_.at((i + 1) % players_.size()));
            }
        }
        else if (choice == 2) {
            //human vs ai
            players_.push_back(std::make_unique<HumanPlayer>(game_config, in, out, players_));
            players_.at(0)->place_ships(in_, out_);

            //push ai to the list of players
            int ai_choice = aiSelect(in, out);
            if (ai_choice == 1) {
                players_.push_back(std::make_unique<CheatingAI>("AI", game_config));
            } else if (ai_choice == 2) {
                players_.push_back(std::make_unique<RandomAI>("AI", game_config));
            } else if (ai_choice == 3) {
                players_.push_back(std::make_unique<SearchAndDestroyAI>("AI", game_config));
            }
            players_.at(1)->place_ships(in_, out_);

            players_.at(0)->set_opponent(*players_.at(1));
            players_.at(1)->set_opponent(*players_.at(0));

        }
        else if (choice == 3) {
            //ai vs ai
            const int num_players = 2;
            for (int i = 0; i < num_players; ++i) {
                int ai_choice = aiSelect(in, out);
                if (ai_choice == 1) {
                    players_.push_back(std::make_unique<CheatingAI>(std::format("AI {}", i+1), game_config));
                } else if (ai_choice == 2) {
                    players_.push_back(std::make_unique<RandomAI>(std::format("AI {}", i+1), game_config));
                } else if (ai_choice == 3) {
                    players_.push_back(std::make_unique<SearchAndDestroyAI>(std::format("AI {}", i+1), game_config));
                }

            }
            players_.at(0)->place_ships(in_, out_);
            players_.at(1)->place_ships(in_, out_);
            players_.at(0)->set_opponent(*players_.at(1));
            players_.at(1)->set_opponent(*players_.at(0));
        }
    }

    /**
     * Play a game of Battleship
     */
    void Game::play() {
        while (true) {
            auto firing_location = cur_player().get_firing_location(in_, out_);
            resolve_current_player_action(firing_location);
            if (is_game_over()) {
                announce_results();
                return;
            }
            advance_to_next_player();
        }
    }


    /**
     * Checks if the game is over. The game is over if any one player has all
     * of their ships destroyed.
     * @return : whether the game is over or not
     */
    bool Game::is_game_over() const {
        constexpr auto is_loser = [](const auto& player) { return player->are_all_ships_destroyed(); };
        return std::ranges::any_of(players_, is_loser);
    }


    /**
     * Resolve the current player shooting their opponent at firing_location
     * @param firing_location : the row,col specifying the location the
     */
    void Game::resolve_current_player_action(const std::pair<int, int>& firing_location) {
        const auto& [row,col] = firing_location;
        const auto firing_result = cur_player().opponent().receive_fire_at(row, col);

        out_ << std::format("{}'s Firing Board\n{}\n\n", cur_player().name(),
                            cur_player().opponent().board().view_as_hidden());
        out_ << std::format("{}'s Placement Board\n{}\n", cur_player().name(), cur_player().board().view_as_visible());


        if (firing_result.is_hit()) {
            cur_player().notify_hit(row, col);
            out_ << std::format("{} hit {}'s {}!\n",
                                cur_player().name(),
                                cur_player().opponent().name(), firing_result.get_ship_hit().value()) << std::endl;
            if (firing_result.was_ship_destroyed()) {
                out_ << std::format("{} destroyed {}'s {}!\n",
                                    cur_player().name(),
                                    cur_player().opponent().name(), firing_result.get_ship_hit().value()
                );
            }
        } else {
            out_ << "Missed." << std::endl;
        }
    }

    /**
     * Switch to the next player's turn
     */
    void Game::advance_to_next_player() {
        cur_player_index_ = (cur_player_index_ + 1) % players_.size();
    }

    /**
     * Announce the final results of the game
     */
    void Game::announce_results() const {
        out_ << cur_player().name() << " won the game!" << std::endl;
    }

    /**
     * Get the current player
     * @return : The current player
     */
    Player& Game::cur_player() {
        return *players_.at(cur_player_index_);
    }

    /**
     * Get the current player
     * @return : The current player
     */
    const Player& Game::cur_player() const {
        return *players_.at(cur_player_index_);
    }
} // BattleShip
