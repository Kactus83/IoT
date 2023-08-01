#ifndef SCD30_ENTITY_H
#define SCD30_ENTITY_H

#include <Arduino.h>
#include "../../../../Entities/abstract/GenericEntity.h"
#include "../../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "SCD30_HardwareManager.h"
#include "SCD30_SpecificEntityState.h"
#include "SCD30_Settings.h"

class SCD30_Entity : public GenericEntity<SCD30_HardwareManager, SCD30_SpecificEntityState, SCD30_Settings> {
public:
    SCD30_Entity(const DeviceConfig& config, const SCD30_Settings& settings)
        : GenericEntity<SCD30_HardwareManager, SCD30_SpecificEntityState, SCD30_Settings>(config, settings) {}
};

#endif // SCD30_ENTITY_H
