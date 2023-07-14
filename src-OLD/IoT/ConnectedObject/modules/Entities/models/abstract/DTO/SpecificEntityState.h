#ifndef SPECIFICENTITYSTATE_H
#define SPECIFICENTITYSTATE_H

#include <Arduino.h>
#include <ArduinoJson.h>

class SpecificEntityState {
public:
    virtual ~SpecificEntityState() {}
    virtual DynamicJsonDocument getState() = 0;
    virtual void setStateFromMQTTMessage(String message) = 0;
};

#endif // SPECIFICENTITYSTATE_H
