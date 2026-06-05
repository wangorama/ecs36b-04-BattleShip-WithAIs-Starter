#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

#include "AIPlayer.h"
#include "GameConfig.h"
#include "Game.h"
#include "Player.h"


int main(int argc, char** argv) {
    unsigned int seed;
    if (argc > 2) {
        seed = std::stoul(argv[2]);
    } else {
        seed = time(nullptr);
    }
    BattleShip::AIPlayer::rng_.seed(seed);

    std::ifstream config_file(argv[1]);
    // BattleShip::GameConfig game_config(config_file);
    BattleShip::GameConfig game_config(7, 7,
                                       {
                                           {'A', 3},
                                           {'B', 3},
                                           {'C', 3}
                                       });
    BattleShip::Game game(game_config, std::cin, std::cout);
    game.play();
    return 0;
}
