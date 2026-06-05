//
// Created by kingdoofus on 5/20/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_HUMANPLAYER_H
#define ECS36BBATTLESHIPWITHAI_HUMANPLAYER_H
#include "Player.h"
#include <format>

namespace BattleShip {
    class HumanPlayer : public Player {
        //player does the move
    public:
        HumanPlayer(const GameConfig& game_config, std::istream& in, std::ostream& out,
               const std::vector<std::unique_ptr<Player> >& other_players):Player(game_config, in, out, other_players){}


        //actions override inherited

        void place_ship(char ship_name, int ship_length, std::istream& in, std::ostream& out) override;

        void place_ships(std::istream& in, std::ostream& out) override;

        std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override;

    };

    };



#endif //ECS36BBATTLESHIPWITHAI_HUMANPLAYER_H
