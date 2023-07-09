#ifndef MESSAGESMANAGER_H
#define MESSAGESMANAGER_H

#include <Arduino.h>
#include "MessagesManagerInterface.h"
#include "../Connectivity/abstract/ConnectivityManagerInterface.h"
#include "../Entities/EntitiesManagerInterface.h"

class MessagesManager : public MessagesManagerInterface {
public:
    MessagesManager() 
    : connectivityManager(nullptr), entitiesManager(nullptr) {}

    void initializeModuleReferences(ConnectivityManagerInterface& connectivityManagerRef, EntitiesManagerInterface& entitiesManagerRef) {
        connectivityManager = &connectivityManagerRef;
        entitiesManager = &entitiesManagerRef;
    }

    void handleIncomingMQTTMessage(const String& topic, const String& message) override {
        if(entitiesManager)
            entitiesManager->handleMQTTMessage(topic, message);
    }

    void sendMQTTMessage(const String& topic, const String& message) override {
        if(connectivityManager)
            connectivityManager->sendMQTTMessage(topic, message);
    }

    void subscribeToMQTTTopic(const String& topic) override {
        if(connectivityManager)
            connectivityManager->subscribeToMQTTTopic(topic);
    }

    void handleHomeAssistantConnectionInterruption() override {
        if(entitiesManager)
            entitiesManager->handleHomeAssistantConnectionInterruption();
    }  

private:
    ConnectivityManagerInterface* connectivityManager;
    EntitiesManagerInterface* entitiesManager;
};

#endif // MESSAGESMANAGER_H
