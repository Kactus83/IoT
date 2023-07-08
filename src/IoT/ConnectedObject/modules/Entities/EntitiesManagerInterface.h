#ifndef ENTITIESMANAGERINTERFACE_H
#define ENTITIESMANAGERINTERFACE_H

#include "./abstract/GenericEntityInterface.h"
#include <Arduino.h>

class EntitiesManagerInterface {
public:
    virtual ~EntitiesManagerInterface() {}

    virtual void setupEntities() = 0;
    virtual void handleHomeAssistantConnectionInterruption() = 0;
    virtual void handleMQTTMessage(const String& message, const String& topic) = 0;
    virtual void entitiesLoop() = 0;
};

#endif // ENTITIESMANAGERINTERFACE_H
