#ifndef MICS_4514_ENTITY_H
#define MICS_4514_ENTITY_H

#include <Arduino.h>
#include "../../../../Entities/abstract/GenericEntity.h"
#include "../../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "MICS_4514_HardwareManager.h"
#include "MICS_4514_SpecificEntityState.h"
#include "MICS_4514_Settings.h"

class MICS_4514_Entity : public GenericEntity<MICS_4514_HardwareManager, MICS_4514_SpecificEntityState, MICS_4514_Settings> {
public:
    MICS_4514_Entity(const DeviceConfig& config, const MICS_4514_Settings& settings)
        : GenericEntity<MICS_4514_HardwareManager, MICS_4514_SpecificEntityState, MICS_4514_Settings>(config, settings) {}
};

#endif // MICS_4514_ENTITY_H
