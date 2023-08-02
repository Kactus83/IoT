#ifndef PM2_5_SENSOR_ENTITY_H
#define PM2_5_SENSOR_ENTITY_H

#include "PM2-5_Sensor_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class PM2_5_Sensor_Entity : public AbstractEntity<PM2_5_Sensor_HardwareState>
{
public:
    PM2_5_Sensor_Entity(const char* unique_id)
    : AbstractEntity<PM2_5_Sensor_HardwareState>("PM2.5 Sensor", "sensor", unique_id) {}
};

#endif // PM2_5_SENSOR_ENTITY_H
