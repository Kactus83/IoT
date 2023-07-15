#ifndef FACTORY_SETTINGS_H
#define FACTORY_SETTINGS_H

#include <Arduino.h>

struct FactorySettings {
    String MQTT_SERVER;
    int MQTT_PORT;
    String MQTT_USERNAME;
    String MQTT_PASSWORD;

    const char* WIFI_SSID;
    const char* WIFI_PASSWORD;

    String INTEGRATION_NAME;
    int MAX_ENTITIES;
    String DEVICE_NAME;
    String UNIQUE_ID;
};

#endif // FACTORY_SETTINGS_H
