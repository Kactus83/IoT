#ifndef ABSTRACT_ENTITYHARDWAREMANAGER_H
#define ABSTRACT_ENTITYHARDWAREMANAGER_H

#include <Arduino.h>
#include "../DTO/SpecificEntityState.h"
#include "../DTO/EntitySettings.h"

template<class SpecificEntityState, class EntitySettings>
class Abstract_EntityHardwareManager {
public:
    Abstract_EntityHardwareManager(SpecificEntityState& state, const EntitySettings& settings)
        : state(state), settings(settings) {}

    virtual ~Abstract_EntityHardwareManager() {}

    virtual void initHardware() = 0;
    virtual void processHardwareLoop() = 0;

protected:
    SpecificEntityState& state;
    const EntitySettings& settings;
};

#endif // ABSTRACT_ENTITYHARDWAREMANAGER_H
