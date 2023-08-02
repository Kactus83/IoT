#ifndef PM10_SENSOR_HARDWARE_STATE_H
#define PM10_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class PM10_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float pm10 = 0.0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["pm10"] = pm10;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        pm10 = doc["pm10"];
    }
};

#endif // PM10_SENSOR_HARDWARE_STATE_H
