#ifndef CO2_SENSOR_HARDWARE_STATE_H
#define CO2_SENSOR_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class CO2_Sensor_HardwareState : public AbstractEntityHardwareState
{
public:
    int co2Level = 0;
};

#endif // CO2_SENSOR_HARDWARE_STATE_H