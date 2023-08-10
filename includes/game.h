#ifndef COUNTER_STRKE_0_1_GAME_H
#define COUNTER_STRKE_0_1_GAME_H

#include <vector>
#include "./player/player.h"
#include "defines.h"
#include <memory>
#include <iostream>

class Game {
public:
    Game() = default;

    void playGame();

private:
    std::vector<std::unique_ptr<player>> m_players;

    void generatePlayers(std::istream &customStream);

    void buyWeaponsPhase();

    void startBattle();

};

#endif //COUNTER_STRKE_0_1_GAME_H
