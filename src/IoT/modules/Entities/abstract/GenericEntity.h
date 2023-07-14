#ifndef GENERICENTITY_H
#define GENERICENTITY_H

#include <Arduino.h>
#include "./DTO/EntityInfo.h"
#include "./DTO/GenericEntityState.h"
#include "./DTO/SpecificEntityState.h"
#include "./modules/EntityDataManager.h"
#include "./modules/Abstract_EntityHardwareManager.h"
#include "./GenericEntityInterface.h"
#include "../../Connectivity/abstract/MQTTMessagesManagerInterface.h"

template<class HardwareManager, class SpecificState, class EntitySettings>

class GenericEntity : public GenericEntityInterface {
public:
    GenericEntity(EntityInfo& info, EntitySettings& settings, MQTTMessagesManagerInterface& messagesManager)
        : info(info), settings(settings), genericState(), dataManager(info, genericState, &specificState, messagesManager), hardwareManager(specificState, settings) {
            genericState.enabled = true;
        }

    virtual ~GenericEntity() {}

    virtual void setup() override {
        hardwareManager.initHardware();
        dataManager.setupEntityForHomeAssistant();
    }

    virtual void reconnect() override {
        loop();
        dataManager.sendState();
    }

    virtual void loop() override {
        hardwareManager.processHardwareLoop();
        dataManager.sendState();
    }

    virtual void handleMQTTMessage(const String& topic, const String& message) override {
        dataManager.handleIncomingMessage(message);
    }

private:
    EntityInfo& info;
    EntitySettings& settings;
    GenericEntityState genericState;
    SpecificState specificState;
    EntityDataManager dataManager;
    MQTTMessagesManagerInterface& messagesManager;
    HardwareManager hardwareManager;
};

#endif // GENERICENTITY_H
