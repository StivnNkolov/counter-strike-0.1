#ifndef COUNTER_STRKE_0_1_PLAYER_H
#define COUNTER_STRKE_0_1_PLAYER_H

#include "../defines.h"
#include "../weapons_libraries.h"
#include "../pistols/pistol.h"
//#include <memory>
#include <iostream>
#include <sstream>


class player {
public:
    explicit player(PlayerVitalData vitalData) : m_vitalData(vitalData) {};

    void buyPistol(std::istream &customStream) {
        std::string inputData;
        PistolVitalData curPistolVitalData;
        int pistolIndex = 0;

        std::getline(customStream, inputData);
        std::istringstream ss(inputData);

        ss >> pistolIndex >> curPistolVitalData.damagePerRound >> curPistolVitalData.clipSize >> curPistolVitalData.remainingAmmo;
        curPistolVitalData.currClipBullets = curPistolVitalData.clipSize;

        m_pistol = weaponsLibrary.at(pistolIndex)(curPistolVitalData);
    };


    PlayerVitalData m_vitalData;
    std::unique_ptr<Pistol> m_pistol{nullptr};

};


#endif //COUNTER_STRKE_0_1_PLAYER_H
