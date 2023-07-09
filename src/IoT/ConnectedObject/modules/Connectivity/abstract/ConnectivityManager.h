#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <Arduino.h>
#include "ConnectivityManagerInterface.h"
#include "../../Messages/MessagesManagerInterface.h"
#include "../../Config/DTO/ConnectivityConfig.h"

template <typename TWiFiManager, typename TMQTTManager>
class ConnectivityManager : public ConnectivityManagerInterface {
public:
    ConnectivityManager(TWiFiManager& wifiManager, TMQTTManager& mqttManager, MessagesManagerInterface& messagesManager, ConnectivityConfig& connectivityConfig)
    : wifiManager(wifiManager), mqttManager(mqttManager), messagesManager(messagesManager), connectivityConfig(connectivityConfig) {}

    void connectHomeAssistant() override {
        wifiManager.connect();
        if(wifiManager.isConnected()){
            mqttManager.connect(wifiManager.getClient());
        }
    }

    void updateHomeAssistantConnection() override {
        checkHomeAssistantConnectionAndReconnect();
        mqttManager.update();
    }

    void subscribeToMQTTTopic(const String& topic) override {
        if(wifiManager.isConnected() && mqttManager.isConnected()){
            mqttManager.subscribeToTopic(topic);
        }
    }

    void sendMQTTMessage(const String& topic, const String& message) override {
        if(wifiManager.isConnected() && mqttManager.isConnected()){
            mqttManager.sendMessage(topic, message);
        }
    }

private:
    TWiFiManager& wifiManager;
    TMQTTManager& mqttManager;
    MessagesManagerInterface& messagesManager;
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
                messagesManager.handleHomeAssistantConnectionInterruption();
            }
        }
    }
};

#endif
