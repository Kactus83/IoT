#ifndef ENTITIESMANAGERINTERFACE_H
#define ENTITIESMANAGERINTERFACE_H

#include <Arduino.h>

class EntitiesManagerInterface {
public:
    virtual ~EntitiesManagerInterface() {}
    virtual void handleIncomingMQTTMessage(const String& topic, const String& message) = 0;
    virtual void handleHomeAssistantConnectionInterruption() = 0;
};

#endif
