#ifndef TEMPERATURE_SENSOR_ENTITY_H
#define TEMPERATURE_SENSOR_ENTITY_H

#include "Temperature_Sensor_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class Temperature_Sensor_Entity : public AbstractEntity<Temperature_Sensor_HardwareState>
{
public:
    Temperature_Sensor_Entity(const char* unique_id)
    : AbstractEntity<Temperature_Sensor_HardwareState>("Temperature Sensor", "sensor", unique_id) {}
};

#endif // TEMPERATURE_SENSOR_ENTITY_H
