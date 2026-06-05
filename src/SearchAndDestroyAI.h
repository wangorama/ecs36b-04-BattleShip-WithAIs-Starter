//
// Created by kingdoofus on 6/1/26.
//

#ifndef ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
#define ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
#include "RandomAI.h"
#include <deque>

namespace BattleShip {
    class SearchAndDestroyAI : public RandomAI {
    public:
        //randomAI is ran first to randomly hit your ship
        //then if it hits any of what the cheater read, attack from the left to right or up to down
        SearchAndDestroyAI(const std::string& name, const GameConfig& game_config);
        std::pair<int, int> get_firing_location(std::istream& in, std::ostream& out) override;
        void process_hit(int row, int col);
        void notify_hit(int row, int col) override;

    private:
        std::deque<std::pair<int,int>> destroy_queue_;
    };
}



#endif //ECS36BBATTLESHIPWITHAI_SEARCHANDDESTROY_H
