#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include "./IoT/ConnectedObject/modules/Config/DTO/FactorySettings.h"

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
