#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include "./IoT/ConnectedObject/modules/Config/DTO/FactorySettings.h"

FactorySettings factorySettings = {
    .MQTT_SERVER = "192.168.1.98",
    .MQTT_PORT = 1883,
    .MQTT_USERNAME = "MQTT",
    .MQTT_PASSWORD = "MQTT_mqtt_2023!",
    .MAX_TOPIC = 10,

    .WIFI_SSID = "24ghz",
    .WIFI_PASSWORD = "PsLyzNnnMBGAcS1jql4H",

    .INTEGRATION_NAME = "flo_perso",
    .DEVICE_NAME = "test_device",
    .UNIQUE_ID = "unic_id",
};

#endif // SETTINGS_H
