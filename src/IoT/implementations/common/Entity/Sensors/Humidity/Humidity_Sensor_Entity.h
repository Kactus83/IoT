#ifndef HUMIDITY_SENSOR_ENTITY_H
#define HUMIDITY_SENSOR_ENTITY_H

#include "Humidity_Sensor_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class Humidity_Sensor_Entity : public AbstractEntity<Humidity_Sensor_HardwareState>
{
public:
    Humidity_Sensor_Entity(const char* unique_id)
    : AbstractEntity<Humidity_Sensor_HardwareState>("Humidity Sensor", "sensor", unique_id) {}
};

#endif // HUMIDITY_SENSOR_ENTITY_H
