#ifndef COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H
#define COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H

#include "pistol.h"

class DesertEaglePistol : public Pistol {
public:
    explicit DesertEaglePistol(PistolVitalData vitalData) : Pistol(vitalData) {};

    void damageApplier(std::unique_ptr<player> &defendingPlayer) override;

};

#endif //COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H
