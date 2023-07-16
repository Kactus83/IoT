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

#ifndef WS12_RGB_LED_ENTITIES_CONFIG_H
#define WS12_RGB_LED_ENTITIES_CONFIG_H

#include "./IoT/modules/Config/DTO/EntitiesConfig.h"
#include "./IoT/modules/Config/DTO/DeviceConfig.h"
#include "./IoT/modules/Entities/implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Settings.h"
#include "./IoT/modules/Entities/implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Entity.h"

class WS12_RGB_LED_EntitiesConfig : public EntitiesConfig {
public:
    WS12_RGB_LED_EntitiesConfig(DeviceConfig& deviceConfig)
        : EntitiesConfig(deviceConfig) {
        entityCount = 1;  // Définir le nombre d'entités
        entities = new GenericEntityInterface*[entityCount]; 
        WS12_RGB_LED_Settings ledSettings = {6, 144}; 
        entities[0] = new WS12_RGB_LED_Entity(deviceConfig, ledSettings);
    }
};

#endif // WS12_RGB_LED_ENTITIES_CONFIG_H
