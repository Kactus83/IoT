#ifndef CO2_SENSOR_ENTITY_H
#define CO2_SENSOR_ENTITY_H

#include "CO2_Sensor_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class CO2_Sensor_Entity : public AbstractEntity<CO2_Sensor_HardwareState>
{
public:
    CO2_Sensor_Entity(const char* unique_id)
    : AbstractEntity<CO2_Sensor_HardwareState>("CO2 Sensor", "sensor", unique_id) {}
};

#endif // CO2_SENSOR_ENTITY_H