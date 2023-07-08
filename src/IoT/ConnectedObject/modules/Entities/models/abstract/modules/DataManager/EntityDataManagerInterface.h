#ifndef ENTITYDATAMANAGERINTERFACE_H
#define ENTITYDATAMANAGERINTERFACE_H

#include <Arduino.h>
#include "../../../../../Messages/MessagesManagerInterface.h"

class EntityDataManagerInterface {
public:
    virtual ~EntityDataManagerInterface() {}

    virtual void setupEntityForHomeAssistant() = 0;
    virtual void sendState() = 0;
    virtual void handleIncomingMessage(const String& message) = 0;

protected:
    MessagesManagerInterface& messagesManager;
};

#endif // ENTITYDATAMANAGERINTERFACE_H
