#ifndef GENERICENTITYINTERFACE_H
#define GENERICENTITYINTERFACE_H

#include <Arduino.h>
#include "./DTO/EntityInfo.h"
#include "../../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class GenericEntityInterface {
public:
    GenericEntityInterface(EntityInfo& info) : info(info) {}
    virtual ~GenericEntityInterface() {}

    virtual void setMessageManager(MQTTMessagesManagerInterface& messagesManager) = 0;
    virtual void setup() = 0;
    virtual void reconnect() = 0;
    virtual void loop() = 0;
    virtual void handleMQTTMessage(const String& topic, const String& message) = 0;
    EntityInfo& info;
};

#endif // GENERICENTITYINTERFACE_H
