#ifndef ENTITIES_CONTAINER_SDC30_H
#define ENTITIES_CONTAINER_SDC30_H

#include "../../../../../abstract/Entity/AsbtractEntitiesContainer.h"
#include "../../../Entity/Sensors/Temperature/Temperature_Sensor_Entity.h"
#include "../../../Entity/Sensors/CO2/CO2_Sensor_Entity.h"
#include "../../../Entity/Sensors/Humidity/Humidity_Sensor_Entity.h"

class EntitiesContainer_SDC30 : public AbstractEntitiesContainer
{
public:
    EntitiesContainer_SDC30(const char* unique_id_base)
        : AbstractEntitiesContainer(entities, 3), // Pass the entities array and its size to the base constructor
          temperatureSensor(generateUniqueId(unique_id_base, "Temperature")),
          co2Sensor(generateUniqueId(unique_id_base, "CO2")),
          humiditySensor(generateUniqueId(unique_id_base, "Humidity"))
    {
        // Initialize the entities array with pointers to the sensor entities
        entities[0] = &temperatureSensor;
        entities[1] = &co2Sensor;
        entities[2] = &humiditySensor;
    }

public:
    // Store sensor entities as public member variables
    Temperature_Sensor_Entity temperatureSensor;
    CO2_Sensor_Entity co2Sensor;
    Humidity_Sensor_Entity humiditySensor;

private:
    // Array of pointers to the sensor entities
    EntityInterface* entities[3];
};

#endif // ENTITIES_CONTAINER_SDC30_H
