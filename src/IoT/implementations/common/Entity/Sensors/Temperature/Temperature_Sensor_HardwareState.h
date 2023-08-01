#ifndef TEMPERATURE_SENSOR_HARDWARE_STATE_H
#define TEMPERATURE_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class Temperature_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float temperature = 0.0;
};

#endif // TEMPERATURE_SENSOR_HARDWARE_STATE_H
