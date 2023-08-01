#ifndef SCD30_HARDWAREMANAGER_H
#define SCD30_HARDWAREMANAGER_H

#include <Arduino.h>
#include "../../../../Entities/abstract/modules/Abstract_EntityHardwareManager.h"
#include "SCD30_Settings.h"
#include "SCD30_SpecificEntityState.h"

class SCD30_HardwareManager : public Abstract_EntityHardwareManager<SCD30_SpecificEntityState, SCD30_Settings> {
public:
    SCD30_HardwareManager(SCD30_SpecificEntityState& state, const SCD30_Settings& settings)
        : Abstract_EntityHardwareManager<SCD30_SpecificEntityState, SCD30_Settings>(state, settings) {}

    virtual void initHardware() override {
        // A compléter avec l'initialisation du matériel SCD30
    }

    virtual void processHardwareLoop() override {
        // A compléter avec la boucle de traitement du matériel SCD30
    }
};

#endif // SCD30_HARDWAREMANAGER_H
