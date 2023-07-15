#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <Arduino.h>
#include "HomeAssistantConnectionManagerInterface.h"
#include "MQTTMessagesManagerInterface.h"
#include "../../Config/DTO/ConnectivityConfig.h"
#include "../../Entities/EntitiesManagerInterface.h"

template <typename TWiFiManager, typename TMQTTManager>
class ConnectivityManager : public HomeAssistantConnectionManagerInterface, public MQTTMessagesManagerInterface {
public:
    ConnectivityManager(TWiFiManager& wifiManager, TMQTTManager& mqttManager, EntitiesManagerInterface& entitiesManager, ConnectivityConfig& connectivityConfig)
    : wifiManager(wifiManager), mqttManager(mqttManager), entitiesManager(entitiesManager), connectivityConfig(connectivityConfig) {}

    void connectHomeAssistant() override {
        Serial.println("Attempting to connect to Home Assistant...");
        wifiManager.connect();
        if(wifiManager.isConnected()){
            Serial.println("Connected to WiFi!");
            mqttManager.connect(wifiManager.getClient());
        }
        if(mqttManager.isConnected()){
            Serial.println("Connected to MQTT!");
        }
    }

    void updateHomeAssistantConnection() override {
        checkHomeAssistantConnectionAndReconnect();
        mqttManager.update();
    }

    void subscribeToMQTTTopic(const char* topic) override {
        Serial.print("Subscribing to MQTT topic: ");
        Serial.println(topic);
        if(wifiManager.isConnected() && mqttManager.isConnected()){
            mqttManager.subscribeToTopic(topic);
        }
    }

    void sendMQTTMessage(const char* topic, const char* message) override {
        Serial.print("Sending MQTT message: ");
        Serial.print(message);
        Serial.print(" to topic: ");
        Serial.println(topic);
        if(wifiManager.isConnected() && mqttManager.isConnected()){
            mqttManager.sendMessage(topic, message);
        }
    }

private:
    TWiFiManager& wifiManager;
    TMQTTManager& mqttManager;
    EntitiesManagerInterface& entitiesManager;
    ConnectivityConfig& connectivityConfig;

    void checkHomeAssistantConnectionAndReconnect() {
        while(!wifiManager.isConnected() || !mqttManager.isConnected()){
            if(!wifiManager.isConnected()){
                wifiManager.connect();
            }
            if(wifiManager.isConnected() && !mqttManager.isConnected()){
                mqttManager.connect(wifiManager.getClient());
            }
            if(!wifiManager.isConnected() || !mqttManager.isConnected()){
                entitiesManager.handleHomeAssistantConnectionInterruption();
            }
        }
    }
};

#endif
