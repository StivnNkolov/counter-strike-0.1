#ifndef COUNTER_STRKE_0_1_GLOCK_PISTOL_H
#define COUNTER_STRKE_0_1_GLOCK_PISTOL_H

#include "pistol.h"

class GlockPistol : public Pistol {
public:
    explicit GlockPistol(PistolVitalData vitalData) : Pistol(vitalData) {};

    void damageApplier(std::unique_ptr<player> &defendingPlayer) override;

};


#endif //COUNTER_STRKE_0_1_GLOCK_PISTOL_H
