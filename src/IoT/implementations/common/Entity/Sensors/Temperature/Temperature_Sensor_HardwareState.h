#ifndef TEMPERATURE_SENSOR_HARDWARE_STATE_H
#define TEMPERATURE_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class Temperature_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float temperature = 0.0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["temperature"] = temperature;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        temperature = doc["temperature"];
    }
};

#endif // TEMPERATURE_SENSOR_HARDWARE_STATE_H
