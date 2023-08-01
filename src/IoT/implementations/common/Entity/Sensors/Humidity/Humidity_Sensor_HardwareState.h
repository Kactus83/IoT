#ifndef HUMIDITY_SENSOR_HARDWARE_STATE_H
#define HUMIDITY_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class Humidity_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    float humidity = 0.0;
};

#endif // HUMIDITY_SENSOR_HARDWARE_STATE_H
