#ifndef SDS011_ENTITY_H
#define SDS011_ENTITY_H

#include <Arduino.h>
#include "../../../../Entities/abstract/GenericEntity.h"
#include "../../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "SDS011_HardwareManager.h"
#include "SDS011_SpecificEntityState.h"
#include "SDS011_Settings.h"

class SDS011_Entity : public GenericEntity<SDS011_HardwareManager, SDS011_SpecificEntityState, SDS011_Settings> {
public:
    SDS011_Entity(const DeviceConfig& config, const SDS011_Settings& settings)
        : GenericEntity<SDS011_HardwareManager, SDS011_SpecificEntityState, SDS011_Settings>(config, settings) {}
};

#endif // SDS011_ENTITY_H
