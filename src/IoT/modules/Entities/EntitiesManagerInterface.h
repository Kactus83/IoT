#ifndef ENTITIESMANAGERINTERFACE_H
#define ENTITIESMANAGERINTERFACE_H

#include <Arduino.h>
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class EntitiesManagerInterface {
public:
    virtual ~EntitiesManagerInterface() {}

    virtual void setMessagesManager(MQTTMessagesManagerInterface& messageManager) = 0;
    virtual void setupEntities() = 0;
    virtual void handleHomeAssistantConnectionInterruption() = 0;
    virtual void handleIncomingMQTTMessage(const String& message, const String& topic) = 0;
    virtual void entitiesLoop() = 0;
};

#endif // ENTITIESMANAGERINTERFACE_H
