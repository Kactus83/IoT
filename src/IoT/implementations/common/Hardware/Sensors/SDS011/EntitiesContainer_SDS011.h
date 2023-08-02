#ifndef ENTITIES_CONTAINER_SDS011_H
#define ENTITIES_CONTAINER_SDS011_H

#include "../../../../../abstract/Entity/EntitiesContainerInterface.h"
#include "../../../../../abstract/Entity/AsbtractEntitiesContainer.h"
#include "../../../Entity/Sensors/PM10/PM10_Sensor_Entity.h"
#include "../../../Entity/Sensors/PM2-5/PM2-5_Sensor_Entity.h"

class EntitiesContainer_SDS011 : public AbstractEntitiesContainer
{
public:
    EntitiesContainer_SDS011(const char* unique_id_base)
        : AbstractEntitiesContainer(entities, 2), // Pass the entities array and its size to the base constructor
          pm10Sensor(generateUniqueId(unique_id_base, "PM10")),
          pm2_5Sensor(generateUniqueId(unique_id_base, "PM2-5"))
    {
        // Initialize the entities array with pointers to the sensor entities
        entities[0] = &pm10Sensor;
        entities[1] = &pm2_5Sensor;
    }

public:
    // Store sensor entities as public member variables
    PM10_Sensor_Entity pm10Sensor;
    PM2_5_Sensor_Entity pm2_5Sensor;

private:
    // Array of pointers to the sensor entities
    EntityInterface* entities[2];
};

#endif // ENTITIES_CONTAINER_SDS011_H
