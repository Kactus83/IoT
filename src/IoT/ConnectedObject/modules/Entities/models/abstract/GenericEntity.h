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

template<class HardwareManager, class SpecificState>

class GenericEntity : public GenericEntityInterface {
public:
    GenericEntity(EntityInfo& info, MessagesManagerInterface& messagesManager)
        : info(info), genericState(), dataManager(info), messagesManager(messagesManager), hardwareManager(), specificState() {
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

    EntityInfo info;

private:
    EntityInfo& info;
    GenericEntityState genericState;
    SpecificState specificState;
    EntityDataManagerInterface dataManager;
    MessagesManagerInterface& messagesManager;
    HardwareManager hardwareManager;
};

#endif // GENERICENTITY_H
