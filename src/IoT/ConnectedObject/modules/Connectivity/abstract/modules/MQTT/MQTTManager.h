#ifndef MQTTMANAGER_H
#define MQTTMANAGER_H

#include <Arduino.h>
#include "MQTTManagerInterface.h"
#include "../../../../Config/DTO/MQTTConfig.h"

class MQTTManager : public MQTTManagerInterface {
public:
    MQTTManager(const MQTTConfig& mqttConfig)
    : mqttConfig(mqttConfig) {}

    void connect(void* client) override {
        if (!isConnected()) {
            connectToBroker(client);
        }
    }

    bool isConnected() override {
        return isConnectedToBroker();
    }

    void update() override {
        updateBroker();
    }

    void subscribeToTopic(const String& topic) override {
        subscribeToBrokerTopic(topic);
    }

    void sendMessage(const String& topic, const String& message) override {
        sendMessageToBroker(topic, message);
    }

protected:
    MQTTConfig mqttConfig;

    virtual void connectToBroker(void* client) = 0;
    virtual bool isConnectedToBroker() = 0;
    virtual void updateBroker() = 0;
    virtual void subscribeToBrokerTopic(const String& topic) = 0;
    virtual void sendMessageToBroker(const String& topic, const String& message) = 0;
};

#endif
