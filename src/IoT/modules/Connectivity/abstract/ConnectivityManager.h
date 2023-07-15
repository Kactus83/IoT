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

    void subscribeToMQTTTopic(const String& topic) override {
        Serial.println("Subscribing to MQTT topic: " + topic);
        if(wifiManager.isConnected() && mqttManager.isConnected()){
            mqttManager.subscribeToTopic(topic);
        }
    }

    void sendMQTTMessage(const String& topic, const String& message) override {
        Serial.println("Sending MQTT message: " + message + " to topic: " + topic);
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
