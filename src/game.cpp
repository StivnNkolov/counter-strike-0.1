#include "../includes/game.h"

void Game::generatePlayers(std::istream &customStream) {
    PlayerVitalData vitalData;
    for (size_t i = 0; i < PLAYERS_COUNT; i++) {
        customStream >> vitalData.health >> vitalData.armor;
        customStream.ignore();
        m_players.emplace_back(std::make_unique<player>(vitalData));
    }
}

void Game::buyWeaponsPhase() {
    for (auto &player: m_players) {
        player->buyPistol(std::cin);
    }
}

void Game::startBattle() {
    while (true) {
        for (size_t i = 0; i < m_players.size(); i++) {
            auto &attackingPlayer = m_players[i];
            std::cout << "PlayerID " << i << " turn:" << std::endl;
            for (size_t j = 0; j < m_players.size(); j++) {
                if (i == j) {
                    continue;
                }
                auto &defendingPlayer = m_players[j];

                if (attackingPlayer->m_pistol->fire(defendingPlayer)) {
                    std::cout << "Player with ID: " << i << " wins!" << std::endl;
                    return;
                }
            }
        }
    }
}

void Game::playGame() {
    generatePlayers(std::cin);
    buyWeaponsPhase();
    startBattle();
}

