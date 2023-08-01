// Entities_Container_SDS011.h

#ifndef ENTITIES_CONTAINER_SDS011_H
#define ENTITIES_CONTAINER_SDS011_H

#include "../../../../../abstract/Entity/EntitiesContainerInterface.h"
#include "../../../../../abstract/Entity/AsbtractEntitiesContainer.h"
#include "../../../Entity/Sensors/CO2/CO2_Sensor_Entity.h"
#include "../../../Entity/Sensors/Humidity/Humidity_Sensor_Entity.h"
#include "../../../Entity/Sensors/Temperature/Temperature_Sensor_Entity.h"

class Entities_Container_SDS011 : public AbstractEntitiesContainer
{
public:
    Entities_Container_SDS011(const char* unique_id_base)
        : AbstractEntitiesContainer(entities, 3), // Pass the entities array and its size to the base constructor
          co2Sensor(generateUniqueId(unique_id_base, "CO2")),
          humiditySensor(generateUniqueId(unique_id_base, "Humidity")),
          temperatureSensor(generateUniqueId(unique_id_base, "Temperature"))
    {
        // Initialize the entities array with pointers to the sensor entities
        entities[0] = &co2Sensor;
        entities[1] = &humiditySensor;
        entities[2] = &temperatureSensor;
    }

private:
    // Store sensor entities as member variables
    CO2_Sensor_Entity co2Sensor;
    Humidity_Sensor_Entity humiditySensor;
    Temperature_Sensor_Entity temperatureSensor;

    // Array of pointers to the sensor entities
    EntityInterface* entities[3];
};

#endif // ENTITIES_CONTAINER_SDS011_H
