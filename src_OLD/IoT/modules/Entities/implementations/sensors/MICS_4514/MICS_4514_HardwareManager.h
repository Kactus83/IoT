#ifndef MICS_4514_HARDWAREMANAGER_H
#define MICS_4514_HARDWAREMANAGER_H

#include <Arduino.h>
#include "../../../../Entities/abstract/modules/Abstract_EntityHardwareManager.h"
#include "MICS_4514_Settings.h"
#include "MICS_4514_SpecificEntityState.h"

class MICS_4514_HardwareManager : public Abstract_EntityHardwareManager<MICS_4514_SpecificEntityState, MICS_4514_Settings> {
public:
    MICS_4514_HardwareManager(MICS_4514_SpecificEntityState& state, const MICS_4514_Settings& settings)
        : Abstract_EntityHardwareManager<MICS_4514_SpecificEntityState, MICS_4514_Settings>(state, settings) {}

    virtual void initHardware() override {
        // A compléter avec l'initialisation du matériel MICS_4514
    }

    virtual void processHardwareLoop() override {
        // A compléter avec la boucle de traitement du matériel MICS_4514
    }
};

#endif // MICS_4514_HARDWAREMANAGER_H
