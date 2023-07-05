#ifndef GENERICENTITY_H
#define GENERICENTITY_H

#include <Arduino.h>
#include "./DTO/EntityInfo.h"
#include "./DTO/GenericEntityState.h"
#include "./DTO/SpecificEntityState.h"
#include "./modules/EntityDataManagerInterface.h"
#include "./modules/EntityHardwareManagerInterface.h"
#include "./GenericEntityInterface.h"

class GenericEntity : public GenericEntityInterface {
public:
    GenericEntity(EntityInfo& info, GenericEntityState& genericState, SpecificEntityState* specificState, EntityDataManagerInterface& dataManager, EntityHardwareManagerInterface& hardwareManager)
        : info(info), genericState(genericState), specificState(specificState), dataManager(dataManager), hardwareManager(hardwareManager) {}
    
    virtual ~GenericEntity() {}

    virtual void setup() override = 0;
    virtual void reconnect() override = 0;
    virtual void loop() override = 0;
    virtual void handleMQTTMessage(const String& topic, const String& message) override = 0;

    EntityInfo info;

protected:
    EntityDataManagerInterface& dataManager;
    EntityHardwareManagerInterface& hardwareManager;

private:
    EntityInfo& info;
    GenericEntityState& genericState;
    SpecificEntityState* specificState;
};

#endif // GENERICENTITY_H
