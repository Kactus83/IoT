#ifndef MQTTMANAGER_PUBSUBCLIENT_H
#define MQTTMANAGER_PUBSUBCLIENT_H

#include <PubSubClient.h>
#include "../../../abstract/MQTT/MQTTManager.h"

class MQTTManager_PubSubClient : public MQTTManager {
public:
    MQTTManager_PubSubClient(const MQTTConfig& mqttConfig, EntitiesManagerInterface& entitiesManager)
    : MQTTManager(mqttConfig, entitiesManager), pubSubClient() {
        pubSubClient.setServer(mqttConfig.SERVER, mqttConfig.PORT);
        pubSubClient.setCallback(staticCallback);
        instance = this;
    }

    void connect(WiFiClient* wifiClient) override {
        pubSubClient.setClient(*wifiClient);
        pubSubClient.connect(mqttConfig.CLIENT_ID, mqttConfig.USERNAME, mqttConfig.PASSWORD);
    }

    bool isConnected() override {
        return pubSubClient.connected();
    }

    void subscribeToTopic(const char* topic) override {
        pubSubClient.subscribe(topic);
    }

    void sendMessage(const char* topic, const char* message) override {
        pubSubClient.publish(topic, message);
    }

    void update() override {
        pubSubClient.loop();
    }

private:
    PubSubClient pubSubClient;
    static MQTTManager_PubSubClient* instance;

    static void staticCallback(char* topic, byte* payload, unsigned int length) {
        instance->handleMQTTMessage(topic, (char*)payload);
    }
};

MQTTManager_PubSubClient* MQTTManager_PubSubClient::instance = nullptr;

#endif
