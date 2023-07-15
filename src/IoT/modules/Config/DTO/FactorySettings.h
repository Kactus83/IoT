#ifndef FACTORY_SETTINGS_H
#define FACTORY_SETTINGS_H

#include <Arduino.h>

struct FactorySettings {
    const char* MQTT_SERVER;
    int MQTT_PORT;
    const char* MQTT_USERNAME;
    const char* MQTT_PASSWORD;

    const char* WIFI_SSID;
    const char* WIFI_PASSWORD;

    const char* INTEGRATION_NAME;
    int8_t MAX_ENTITIES;
    const char* DEVICE_NAME;
    const char* UNIQUE_ID;
};

#endif // FACTORY_SETTINGS_H
