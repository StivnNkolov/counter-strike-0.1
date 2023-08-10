#include "../includes/pistols/desert_eagle_pistol.h"
#include "../includes/player/player.h"

void GlockPistol::damageApplier(std::unique_ptr<player> &defendingPlayer) {
    for (size_t shotsFired = 1; shotsFired <= GlockInfo::numberOfBulletsToFireAtOneTime; shotsFired++) {

        if (defendingPlayer->m_vitalData.armor > 0) {
            actionsWhenEnemyHaveArmor(defendingPlayer, GlockInfo::damageToArmorPercentage, GlockInfo::damageToHealthPercentage);
        } else {
            defendingPlayer->m_vitalData.health -= m_pistolVitalData.damagePerRound;
        }

        m_pistolVitalData.currClipBullets--;
        printMessageAfterShooting(defendingPlayer);

        if (isTargetDeath(defendingPlayer)) {
            break;
        }
        if (isClipEmpty() && shotsFired != GlockInfo::numberOfBulletsToFireAtOneTime) {
            reload();
            break;
        }
    }
}