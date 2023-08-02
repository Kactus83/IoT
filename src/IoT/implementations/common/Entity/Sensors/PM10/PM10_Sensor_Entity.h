#ifndef PM10_SENSOR_ENTITY_H
#define PM10_SENSOR_ENTITY_H

#include "PM10_Sensor_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class PM10_Sensor_Entity : public AbstractEntity<PM10_Sensor_HardwareState>
{
public:
    PM10_Sensor_Entity(const char* unique_id)
    : AbstractEntity<PM10_Sensor_HardwareState>("PM10 Sensor", "sensor", unique_id) {}
};

#endif // PM10_SENSOR_ENTITY_H
