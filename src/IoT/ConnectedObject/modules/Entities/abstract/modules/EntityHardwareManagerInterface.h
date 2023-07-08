#ifndef ENTITYHARDWAREMANAGERINTERFACE_H
#define ENTITYHARDWAREMANAGERINTERFACE_H

#include <Arduino.h>
#include "../../../Messages/MessagesManagerInterface.h"

class EntityHardwareManagerInterface {
public:
    virtual ~EntityHardwareManagerInterface() {}

    virtual void initHardware() = 0;
    virtual void processHardwareLoop() = 0;

protected:
    MessagesManagerInterface& messagesManager;
};

#endif // ENTITYHARDWAREMANAGERINTERFACE_H
