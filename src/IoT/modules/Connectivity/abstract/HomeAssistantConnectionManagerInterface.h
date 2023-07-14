#ifndef HOMEASSISTANTCONNECTIONMANAGERINTERFACE_H
#define HOMEASSISTANTCONNECTIONMANAGERINTERFACE_H

#include <Arduino.h>

class HomeAssistantConnectionManagerInterface {
public:
    virtual ~HomeAssistantConnectionManagerInterface() {}
    virtual void connectHomeAssistant() = 0;
    virtual void updateHomeAssistantConnection() = 0;
};

#endif
