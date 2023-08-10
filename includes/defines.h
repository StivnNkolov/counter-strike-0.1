#ifndef DEFINES_H_
#define DEFINES_H_


enum class PistolType {
    GLOCK = 0, DESERT_EAGLE = 1
};

enum GeneralDefines {
    PLAYER_ONE = 0,
    PLAYER_TWO = 1,

    PLAYERS_COUNT = 2
};

struct PlayerVitalData {
    int health{};
    int armor{};
};

struct PistolVitalData {
    int damagePerRound{};
    int clipSize{};
    int remainingAmmo{};
    int currClipBullets{};
};


namespace DesertEagleInfo {
    const int damageToHealthPercentage = 75;
    const int damageToArmorPercentage = 25;
}

namespace GlockInfo {
    const int damageToHealthPercentage = 50;
    const int damageToArmorPercentage = 50;
    const int numberOfBulletsToFireAtOneTime = 3;

}

#endif /* DEFINES_H_ */
