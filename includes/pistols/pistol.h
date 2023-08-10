#ifndef COUNTER_STRKE_0_1_PISTOL_H
#define COUNTER_STRKE_0_1_PISTOL_H

#include "../defines.h"
#include <memory>
#include <iostream>

class player;

class Pistol {
public:

    explicit Pistol(PistolVitalData &vitalData);

    virtual ~Pistol() = default;

    virtual bool fire(std::unique_ptr<player> &defendingPlayer);

    virtual void reload();

    bool isClipEmpty() const;

    virtual void damageApplier(std::unique_ptr<player> &defendingPlayer) = 0;

    virtual bool isTargetDeath(std::unique_ptr<player> &defendingPlayer);

    virtual void
    actionsWhenEnemyHaveArmor(std::unique_ptr<player> &defendingPlayer, int damageToArmor, int damageToHealth);

protected:


    PistolVitalData m_pistolVitalData;
    bool m_isAmmoEmpty{false};

    virtual void printMessageAfterShooting(std::unique_ptr<player> &defendingPlayer);

private:
    void printNoAmmoMessage() {
        std::cout << "No ammo left" << std::endl;
    }

    void actionsWhenNotEnoughAmmoToFillClip();

    void printAfterReloadMessage() const {
        std::cout << "currClipBullets: " << m_pistolVitalData.currClipBullets << ", remainingAmmo: "
                  << m_pistolVitalData.remainingAmmo << std::endl;
    }
};


#endif //COUNTER_STRKE_0_1_PISTOL_H
