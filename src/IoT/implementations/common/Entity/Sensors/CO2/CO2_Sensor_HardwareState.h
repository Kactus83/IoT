#ifndef CO2_SENSOR_HARDWARE_STATE_H
#define CO2_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class CO2_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    int CO2 = 0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["CO2"] = CO2;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        CO2 = doc["CO2"];
    }
};

#endif // CO2_SENSOR_HARDWARE_STATE_H
