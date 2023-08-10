#ifndef COUNTER_STRKE_0_1_WEAPONS_LIBRARIES_H
#define COUNTER_STRKE_0_1_WEAPONS_LIBRARIES_H

#include "pistols/desert_eagle_pistol.h"
#include "pistols/glock_pistol.h"

#include <unordered_map>
#include <memory>
#include <functional>


template<class T>
std::unique_ptr<T> weapon_creator(const PistolVitalData &vitalData) {
    return std::make_unique<T>(vitalData);
}


const static std::unordered_map<int, std::function<std::unique_ptr<Pistol>(const PistolVitalData &weaponData)>> weaponsLibrary {
        {static_cast<int>(PistolType::GLOCK), weapon_creator<GlockPistol>},
        {static_cast<int>(PistolType::DESERT_EAGLE), weapon_creator<DesertEaglePistol>}
};


#endif //COUNTER_STRKE_0_1_WEAPONS_LIBRARIES_H
