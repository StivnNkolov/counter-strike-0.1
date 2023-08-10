#include "../includes/pistols/desert_eagle_pistol.h"
#include "../includes/player/player.h"

void DesertEaglePistol::damageApplier(std::unique_ptr<player> &defendingPlayer) {
    if (defendingPlayer->m_vitalData.armor > 0) {
        actionsWhenEnemyHaveArmor(defendingPlayer, DesertEagleInfo::damageToArmorPercentage,
                                  DesertEagleInfo::damageToHealthPercentage);
    } else {
        defendingPlayer->m_vitalData.health -= m_pistolVitalData.damagePerRound;
    }
    m_pistolVitalData.currClipBullets--;

    printMessageAfterShooting(defendingPlayer);
}
