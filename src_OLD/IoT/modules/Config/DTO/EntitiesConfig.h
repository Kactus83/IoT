#ifndef ENTITIES_CONFIG_H
#define ENTITIES_CONFIG_H

#include "./DeviceConfig.h"
#include "../../Entities/abstract/GenericEntityInterface.h"

class EntitiesConfig {
public:
    EntitiesConfig(DeviceConfig& deviceConfig) : deviceConfig(deviceConfig), entityCount(0) {
        entities = new GenericEntityInterface*[deviceConfig.MAX_ENTITIES];
    }
    virtual ~EntitiesConfig() {}

    GenericEntityInterface** entities;
    int entityCount;

protected:
    DeviceConfig& deviceConfig;
};

#endif // ENTITIES_CONFIG_H
