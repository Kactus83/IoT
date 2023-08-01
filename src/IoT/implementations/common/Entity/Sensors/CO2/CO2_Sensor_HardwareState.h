#ifndef CO2_SENSOR_HARDWARE_STATE_H
#define CO2_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class CO2_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    int co2Level = 0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["co2Level"] = co2Level;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        co2Level = doc["co2Level"];
    }
};

#endif // CO2_SENSOR_HARDWARE_STATE_H
