#ifndef HUMIDITY_SENSOR_HARDWARE_STATE_H
#define HUMIDITY_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class Humidity_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float humidity = 0.0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["humidity"] = humidity;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        humidity = doc["humidity"];
    }
};

#endif // HUMIDITY_SENSOR_HARDWARE_STATE_H
