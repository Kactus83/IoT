#ifndef PM2_5_SENSOR_HARDWARE_STATE_H
#define PM2_5_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class PM2_5_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float pm2_5 = 0.0;

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["pm2_5"] = pm2_5;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        pm2_5 = doc["pm2_5"];
    }
};

#endif // PM2_5_SENSOR_HARDWARE_STATE_H
