#ifndef GENERICENTITY_H
#define GENERICENTITY_H

#include <Arduino.h>
#include "./DTO/EntityInfo.h"
#include "./DTO/GenericEntityState.h"
#include "./DTO/SpecificEntityState.h"
#include "./modules/DataManager/EntityDataManagerInterface.h"
#include "./modules/EntityHardwareManagerInterface.h"
#include "./GenericEntityInterface.h"
#include "../../../Messages/MessagesManagerInterface.h"

class GenericEntity : public GenericEntityInterface {
public:
    GenericEntity(EntityInfo& info, GenericEntityState& genericState, SpecificEntityState* specificState, EntityDataManagerInterface& dataManager, EntityHardwareManagerInterface& hardwareManager, MessagesManagerInterface& messagesManager)
        : info(info), genericState(genericState), specificState(specificState), dataManager(dataManager), hardwareManager(hardwareManager), messagesManager(messagesManager) {}
    
    virtual ~GenericEntity() {}

    virtual void setup() override {
        hardwareManager.initHardware();
        dataManager.setupEntityForHomeAssistant();
    }

    virtual void reconnect() override {
        loop();
        dataManager.sendState();
    };

    virtual void loop() override {
        hardwareManager.processHardwareLoop();
        dataManager.sendState();
    };

    virtual void handleMQTTMessage(const String& topic, const String& message) override {
        dataManager.handleIncomingMessage(message);
    }

    EntityInfo info;

protected:
    EntityDataManagerInterface& dataManager;
    EntityHardwareManagerInterface& hardwareManager;
    MessagesManagerInterface& messagesManager;

private:
    EntityInfo& info;
    GenericEntityState& genericState;
    SpecificEntityState* specificState;
};

#endif // GENERICENTITY_H
