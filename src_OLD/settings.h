#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include "./IoT/modules/Config/DTO/FactorySettings.h"

FactorySettings factorySettings = {
    "192.168.1.98", // MQTT_SERVER
    1883, // MQTT_PORT
    "MQTT", // MQTT_USERNAME
    "MQTT_mqtt_2023!", // MQTT_PASSWORD
    "24ghz", // WIFI_SSID
    "PsLyzNnnMBGAcS1jql4H", // WIFI_PASSWORD
    "flo_perso", // INTEGRATION_NAME
    10, // MAX_ENTITIES
    "test_device", // DEVICE_NAME
    "unic_id" // UNIQUE_ID
};

#endif // SETTINGS_H

#ifndef TEST_ENTITIES_CONFIG_H
#define TEST_ENTITIES_CONFIG_H

#include "./IoT/modules/Config/DTO/EntitiesConfig.h"
#include "./IoT/modules/Config/DTO/DeviceConfig.h"
#include "./IoT/modules/Entities/implementations/sensors/MICS_4514/MICS_4514_Settings.h"
#include "./IoT/modules/Entities/implementations/sensors/MICS_4514/MICS_4514_Entity.h"
#include "./IoT/modules/Entities/implementations/sensors/SCD30/SCD30_Settings.h"
#include "./IoT/modules/Entities/implementations/sensors/SCD30/SCD30_Entity.h"
#include "./IoT/modules/Entities/implementations/sensors/SDS011/SDS011_Settings.h"
#include "./IoT/modules/Entities/implementations/sensors/SDS011/SDS011_Entity.h"

class TestEntitiesConfig : public EntitiesConfig {
public:
    TestEntitiesConfig(DeviceConfig& deviceConfig)
        : EntitiesConfig(deviceConfig) {
        entityCount = 3;  // Nous avons trois entités
        entities = new GenericEntityInterface*[entityCount]; 
        
        MICS_4514_Settings micsSettings(2, 3, 0);  // remplacer 2 et 3 par les vraies broches
        entities[0] = new MICS_4514_Entity(deviceConfig, micsSettings);
        
        SCD30_Settings scdSettings(1);  // Index mis à jour
        entities[1] = new SCD30_Entity(deviceConfig, scdSettings);
        
        SDS011_Settings sdsSettings(4, 5, 2);  // Index et broches mis à jour
        entities[2] = new SDS011_Entity(deviceConfig, sdsSettings);
    }
};

#endif // TEST_ENTITIES_CONFIG_H
