#ifndef SDS011_HARDWAREMANAGER_H
#define SDS011_HARDWAREMANAGER_H

#include <Arduino.h>
#include "../../../../Entities/abstract/modules/Abstract_EntityHardwareManager.h"
#include "SDS011_Settings.h"
#include "SDS011_SpecificEntityState.h"

class SDS011_HardwareManager : public Abstract_EntityHardwareManager<SDS011_SpecificEntityState, SDS011_Settings> {
public:
    SDS011_HardwareManager(SDS011_SpecificEntityState& state, const SDS011_Settings& settings)
        : Abstract_EntityHardwareManager<SDS011_SpecificEntityState, SDS011_Settings>(state, settings) {}

    virtual void initHardware() override {
        // A compléter avec l'initialisation du matériel SDS011
    }

    virtual void processHardwareLoop() override {
        // A compléter avec la boucle de traitement du matériel SDS011
    }
};

#endif // SDS011_HARDWAREMANAGER_H
