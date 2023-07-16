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
#include "../../Config/DTO/DeviceConfig.h"

template<class HardwareManager, class SpecificState, class EntitySettings>
class GenericEntity : public GenericEntityInterface {
public:
    GenericEntity(const DeviceConfig& config, const EntitySettings& settings)
        : GenericEntityInterface(info), info(config, settings), settings(settings), genericState(), hardwareManager(specificState, settings), dataManager(info, genericState, &specificState) {
            genericState.enabled = true;
        }

    virtual ~GenericEntity() {}

    void setMessageManager(MQTTMessagesManagerInterface& messagesManager) {
        this->messagesManager = &messagesManager;
        dataManager.setMessagesManager(messagesManager);
    }

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
    EntityInfo info;
    const EntitySettings& settings;
    GenericEntityState genericState;
    SpecificState specificState;
    EntityDataManager dataManager;
    HardwareManager hardwareManager;
    MQTTMessagesManagerInterface* messagesManager; 
};

#endif // GENERICENTITY_H
