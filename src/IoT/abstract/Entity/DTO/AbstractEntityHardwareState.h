#ifndef ABSTRACT_ENTITY_HARDWARE_STATE_H
#define ABSTRACT_ENTITY_HARDWARE_STATE_H

#include <ArduinoJson.h>
#include <Arduino.h>

class AbstractEntityHardwareState
{
public:
    virtual ~AbstractEntityHardwareState() {}
    virtual DynamicJsonDocument getJSONHardwareState() = 0;
    virtual void setHardwareStateFromJSON(const String& json) = 0;
};

#endif // ABSTRACT_ENTITY_HARDWARE_STATE_H
