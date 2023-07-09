#ifndef MESSAGESMANAGERINTERFACE_H
#define MESSAGESMANAGERINTERFACE_H

#include <Arduino.h>

class MessagesManagerInterface {
public:
    virtual ~MessagesManagerInterface() {}

    virtual void initializeModuleReferences(ConnectivityManagerInterface& connectivityManagerRef, EntitiesManagerInterface& entitiesManagerRef) = 0;
    virtual void handleIncomingMQTTMessage(const String& topic, const String& message) = 0;
    virtual void sendMQTTMessage(const String& topic, const String& message) = 0;
    virtual void subscribeToMQTTTopic(const String& topic) = 0;
    virtual void handleHomeAssistantConnectionInterruption() = 0;  
};

#endif
