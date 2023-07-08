#ifndef MESSAGESMANAGER_H
#define MESSAGESMANAGER_H

#include <Arduino.h>
#include "MessagesManagerInterface.h"
#include "../Connectivity/abstract/ConnectivityManagerInterface.h"
#include "../Entities/EntitiesManagerInterface.h"

class MessagesManager : public MessagesManagerInterface {
public:
    MessagesManager(ConnectivityManagerInterface& connectivityManager, EntitiesManagerInterface& entitiesManager)
    : connectivityManager(connectivityManager), entitiesManager(entitiesManager) {}

    void handleIncomingMQTTMessage(const String& topic, const String& message) override {
        entitiesManager.handleMQTTMessage(topic, message);
    }

    void sendMQTTMessage(const String& topic, const String& message) override {
        connectivityManager.sendMQTTMessage(topic, message);
    }

    void subscribeToMQTTTopic(const String& topic) override {
        connectivityManager.subscribeToMQTTTopic(topic);
    }

    void handleHomeAssistantConnectionInterruption() override {
        entitiesManager.handleHomeAssistantConnectionInterruption();
    }  

private:
    ConnectivityManagerInterface& connectivityManager;
    EntitiesManagerInterface& entitiesManager;
};

#endif // MESSAGESMANAGER_H
