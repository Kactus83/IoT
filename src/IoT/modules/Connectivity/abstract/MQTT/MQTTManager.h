#ifndef MQTTMANAGER_H
#define MQTTMANAGER_H

#include <Arduino.h>
#include <WiFiClient.h>
#include "../../../Config/DTO/MQTTConfig.h"
#include "../../../Entities/EntitiesManagerInterface.h"

class MQTTManager {
public:
    MQTTManager(const MQTTConfig& mqttConfig, EntitiesManagerInterface& entitiesManager) : mqttConfig(mqttConfig), entitiesManager(entitiesManager) {}

    virtual ~MQTTManager() {}

    virtual void connect(WiFiClient* wifiClient) = 0;
    virtual bool isConnected() = 0;
    virtual void subscribeToTopic(const char* topic) = 0;
    virtual void sendMessage(const char* topic, const char* message) = 0;
    virtual void update() = 0;

protected:
    const MQTTConfig& mqttConfig;
    EntitiesManagerInterface& entitiesManager;

    void handleMQTTMessage(const char* topic, const char* message) {
        entitiesManager.handleIncomingMQTTMessage(topic, message);
    }
};

#endif
