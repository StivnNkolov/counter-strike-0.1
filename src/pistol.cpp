#include "../includes/pistols/pistol.h"
#include "../includes/player/player.h"
#include <iostream>

Pistol::Pistol(PistolVitalData &vitalData) : m_pistolVitalData(vitalData) {}

bool Pistol::fire(std::unique_ptr<player> &defendingPlayer) {
    if (isClipEmpty()) {
        reload();
        return false;
    }
    damageApplier(defendingPlayer);
    std::cout << std::endl;
    if (isTargetDeath(defendingPlayer)) {
        return true;
    }
    return false;
}

void Pistol::reload() {
    if (m_isAmmoEmpty) {
        printNoAmmoMessage();
        return;
    }
    std::cout << "Reloading..." << std::endl;
    if (m_pistolVitalData.remainingAmmo < m_pistolVitalData.clipSize) {
        actionsWhenNotEnoughAmmoToFillClip();
        printAfterReloadMessage();
        return;
    }

    m_pistolVitalData.currClipBullets = m_pistolVitalData.clipSize;
    m_pistolVitalData.remainingAmmo -= m_pistolVitalData.clipSize;
    if (m_pistolVitalData.remainingAmmo == 0) {
        m_isAmmoEmpty = true;
    }
    printAfterReloadMessage();
}

bool Pistol::isClipEmpty() const {
    return m_pistolVitalData.currClipBullets == 0;
}

bool Pistol::isTargetDeath(std::unique_ptr<player> &defendingPlayer) {
    return defendingPlayer->m_vitalData.health <= 0;
}

void Pistol::actionsWhenEnemyHaveArmor(std::unique_ptr<player> &defendingPlayer, const int damageToArmor,
                                       const int damageToHealth) {
    defendingPlayer->m_vitalData.armor -= m_pistolVitalData.damagePerRound * damageToArmor / 100;

    if (defendingPlayer->m_vitalData.armor < 0) {
        defendingPlayer->m_vitalData.health -= std::abs(defendingPlayer->m_vitalData.armor);
        defendingPlayer->m_vitalData.armor = 0;
    }
    defendingPlayer->m_vitalData.health -= m_pistolVitalData.damagePerRound * damageToHealth / 100;
}

inline void Pistol::printMessageAfterShooting(std::unique_ptr<player> &defendingPlayer) {
    std::cout << "Enemy left with: " << defendingPlayer->m_vitalData.health << " health and "
              << defendingPlayer->m_vitalData.armor << " armor" << std::endl;
}

void Pistol::actionsWhenNotEnoughAmmoToFillClip() {
    m_pistolVitalData.currClipBullets = m_pistolVitalData.remainingAmmo;
    m_pistolVitalData.remainingAmmo = 0;
    m_isAmmoEmpty = true;
}