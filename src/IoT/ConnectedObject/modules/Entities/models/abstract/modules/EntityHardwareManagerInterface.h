#ifndef ENTITYHARDWAREMANAGERINTERFACE_H
#define ENTITYHARDWAREMANAGERINTERFACE_H

#include <Arduino.h>

class EntityHardwareManagerInterface {
public:
    virtual ~EntityHardwareManagerInterface() {}

    virtual void initHardware() = 0;
    virtual void processHardwareLoop() = 0;
};

#endif // ENTITYHARDWAREMANAGERINTERFACE_H
