#ifndef MQTTMANAGER_PUBSUBCLIENT_H
#define MQTTMANAGER_PUBSUBCLIENT_H

#include <PubSubClient.h>
#include "../../../abstract/MQTT/MQTTManager.h"

class MQTTManager_PubSubClient : public MQTTManager {
public:
    MQTTManager_PubSubClient(const MQTTConfig& mqttConfig, EntitiesManagerInterface& entitiesManager)
    : MQTTManager(mqttConfig, entitiesManager), pubSubClient() {
        pubSubClient.setServer(mqttConfig.SERVER.c_str(), mqttConfig.PORT);
        pubSubClient.setCallback(staticCallback);
        instance = this;
    }

    void connect(WiFiClient* wifiClient) override {
        pubSubClient.setClient(*wifiClient);
        pubSubClient.connect(mqttConfig.CLIENT_ID.c_str(), mqttConfig.USERNAME.c_str(), mqttConfig.PASSWORD.c_str());
    }

    bool isConnected() override {
        return pubSubClient.connected();
    }

    void subscribeToTopic(const String& topic) override {
        pubSubClient.subscribe(topic.c_str());
    }

    void sendMessage(const String& topic, const String& message) override {
        pubSubClient.publish(topic.c_str(), message.c_str());
    }

    void update() override {
        pubSubClient.loop();
    }

private:
    PubSubClient pubSubClient;
    static MQTTManager_PubSubClient* instance;

    static void staticCallback(char* topic, byte* payload, unsigned int length) {
        instance->handleMQTTMessage(String(topic), String((char*)payload));
    }
};

MQTTManager_PubSubClient* MQTTManager_PubSubClient::instance = nullptr;

#endif
