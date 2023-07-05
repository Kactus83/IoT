#include "PubSubClient.h" 
#include "WiFi.h" 
#include "../../../abstract/modules/MQTT/MQTTManager.h"

class MQTTManager_PubSubClient : public MQTTManager {
public:
    MQTTManager_PubSubClient(const MQTTConfig& mqttConfig, MessagesManagerInterface& messagesManager)
    : MQTTManager(mqttConfig, messagesManager) {
        pubSubClient.setServer(mqttConfig.SERVER.c_str(), mqttConfig.PORT);
        pubSubClient.setCallback(staticCallback);
        instance = this;
    }

protected:
    PubSubClient pubSubClient;
    static MQTTManager_PubSubClient* instance; 

    static void staticCallback(char* topic, byte* payload, unsigned int length) {
        instance->handleMQTTMessage(String(topic), String((char*)payload));  
    }

    void connectToBroker(void* client) override {
        pubSubClient.setClient(*(WiFiClient*)client);
        pubSubClient.connect(mqttConfig.CLIENT_ID.c_str(), mqttConfig.USERNAME.c_str(), mqttConfig.PASSWORD.c_str());
    }

    bool isConnectedToBroker() override {
        return pubSubClient.connected();
    }

    void updateBroker() override {
        pubSubClient.loop();
    }

    void subscribeToBrokerTopic(const String& topic) override {
        pubSubClient.subscribe(topic.c_str());
    }

    void sendMessageToBroker(const String& topic, const String& message) override {
        pubSubClient.publish(topic.c_str(), message.c_str());
    }
};
   
MQTTManager_PubSubClient* MQTTManager_PubSubClient::instance = nullptr;
