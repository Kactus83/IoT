#ifndef ABSTRACT_ENTITY_HARDWARE_STATE_H
#define ABSTRACT_ENTITY_HARDWARE_STATE_H

#include <ArduinoJson.h>
#include <Arduino.h>

/**
 * @brief Abstract class for hardware-specific states of entities.
 * 
 * Provides interfaces to convert the hardware state into JSON and vice-versa.
 * Implementations of entities must specify their specific hardware states 
 * by subclassing this abstract class.
 */
class AbstractEntityHardwareState
{
public:
    virtual ~AbstractEntityHardwareState() {}

    // Retrieves the hardware state in JSON format
    virtual DynamicJsonDocument getJSONHardwareState() = 0;
    
    // Sets the hardware state from a given JSON string
    virtual void setHardwareStateFromJSON(const String& json) = 0;
};

#endif // ABSTRACT_ENTITY_HARDWARE_STATE_H
